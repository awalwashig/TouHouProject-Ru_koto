use std::any::TypeId;
use std::collections::HashMap;
use std::error::Error;
use std::future::Future;
use std::sync::Arc;

use crate::api::ApiSet;
use futures_util::StreamExt;
use serde_json::Value;
use tokio::task::spawn;
use tokio_tungstenite::connect_async;

use crate::config::Config;
use crate::handler::{
    ApiResponse, Event, EventCollection, GroupMsg, HandlerFn, Heartbeat, PrivateMsg,
};
use crate::Unknown;

pub struct Client {
    config: Config,
    handler_map: HashMap<TypeId, HandlerFn>,
}

pub trait EventHandlerRegister<T>
where
    T: Event + 'static,
{
    fn register<R>(&mut self, event_handler: impl Fn(Box<T>, Arc<ApiSet>) -> R + 'static)
    where
        R: Future<Output = ()> + 'static + Send;
}

impl Client {
    pub fn new(config: Config) -> Self {
        Self {
            config,
            handler_map: Default::default(),
        }
    }

    async fn handle_message(&self, msg: &str, api: Arc<ApiSet>) {
        let raw_json: Value = serde_json::from_str(msg).expect("Failed to parse message!");
        if !raw_json.is_object() {
            return;
        }
        let obj = raw_json.as_object().unwrap();
        let type_id;
        let event: Box<EventCollection>;
        if obj.contains_key("status")
            && obj.contains_key("retcode")
            && obj.contains_key("data")
            && obj.contains_key("echo")
        {
            let api_response: ApiResponse =
                serde_json::from_str(msg).expect("Failed to parse api response!");
            event = Box::new(EventCollection::ApiResponse(api_response));
            type_id = TypeId::of::<ApiResponse>();
        } else if obj.contains_key("post_type")
            && obj.get("post_type").unwrap().as_str().unwrap() == "message"
        {
            if let Ok(group_msg) = serde_json::from_str::<GroupMsg>(msg) {
                event = Box::new(EventCollection::GroupMsg(group_msg));
                type_id = TypeId::of::<GroupMsg>();
            } else if let Ok(private_msg) = serde_json::from_str::<PrivateMsg>(msg) {
                event = Box::new(EventCollection::PrivateMsg(private_msg));
                type_id = TypeId::of::<PrivateMsg>();
            } else {
                type_id = TypeId::of::<Unknown>();
                event = Box::new(EventCollection::Unknown(Unknown { raw_json }));
            }
        } else {
            type_id = TypeId::of::<Unknown>();
            event = Box::new(EventCollection::Unknown(Unknown { raw_json }));
        }
        if let Some(handler) = self.handler_map.get(&type_id) {
            handler(event, api);
        }
    }

    pub async fn start(self) -> Result<Arc<ApiSet>, Box<dyn Error>> {
        let url = self.config.to_url().unwrap();
        let (stream, _) = connect_async(url)
            .await
            .expect("Failed to connect to ws server!");
        let (write, read) = stream.split();

        let api_set = Arc::new(ApiSet::new(write));

        read.for_each(|msg| async {
            match msg {
                Ok(msg) => {
                    let raw_msg = msg.to_text().expect("Failed to parse ws message!");
                    self.handle_message(raw_msg, api_set.clone()).await;
                }
                Err(e) => {
                    eprintln!("Error: {}", e);
                }
            }
        })
        .await;

        Ok(api_set.clone())
    }
}

macro_rules! impl_event_handler_register {
    ($event: ident) => {
        impl EventHandlerRegister<$event> for Client {
            fn register<R>(
                &mut self,
                event_handler: impl Fn(Box<$event>, Arc<ApiSet>) -> R + 'static,
            ) where
                R: Future<Output = ()> + 'static + Send,
            {
                let handler_fn = Box::new(move |event: Box<EventCollection>, api| {
                    if let EventCollection::$event(event) = *event {
                        let event = Box::new(event);
                        spawn(event_handler(event, api));
                    } else {
                        let panic_msg = format!(
                            "Unexpected event type: {:?}, expected: {}",
                            event,
                            stringify!($event)
                        );
                        panic!("{}", panic_msg);
                    }
                });
                self.handler_map.insert(TypeId::of::<$event>(), handler_fn);
            }
        }
    };
}

impl_event_handler_register!(GroupMsg);
impl_event_handler_register!(PrivateMsg);
impl_event_handler_register!(Heartbeat);
impl_event_handler_register!(ApiResponse);
impl_event_handler_register!(Unknown);

#[cfg(test)]
mod test {
    use tokio::task::LocalSet;

    use crate::client::{Client, EventHandlerRegister};
    use crate::config::Config;
    use crate::handler::GroupMsg;
    #[tokio::test]
    async fn test_reg() {
        let mut cli = Client::new(Config {
            host: "10.147.18.50".to_owned(),
            port: 3001,
            token: None,
        });

        cli.register(|event: Box<GroupMsg>, api| async move {
            println!("{:?}", event);
        });

        cli.start().await.unwrap();
    }
}
