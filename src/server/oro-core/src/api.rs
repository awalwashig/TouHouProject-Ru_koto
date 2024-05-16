use futures_util::stream::SplitSink;
use futures_util::SinkExt;
use serde::{Deserialize, Serialize};
use tokio::net::TcpStream;
use tokio::sync::RwLock;
use tokio_tungstenite::tungstenite::Message;
use tokio_tungstenite::{MaybeTlsStream, WebSocketStream};

#[derive(Serialize, Deserialize, Debug)]
pub struct Status {
    pub online: Option<bool>,
    pub good: Option<bool>,
}

#[derive(Debug)]
pub struct ApiSet {
    sender: RwLock<SplitSink<WebSocketStream<MaybeTlsStream<TcpStream>>, Message>>,
    echo: RwLock<String>,
}

impl ApiSet {
    pub(crate) fn new(
        sender: SplitSink<WebSocketStream<MaybeTlsStream<TcpStream>>, Message>,
    ) -> Self {
        Self {
            sender: RwLock::new(sender),
            echo: RwLock::new(String::new()),
        }
    }

    async fn make_api_call(
        &self,
        action: &str,
        params: serde_json::Value,
    ) -> Result<(), Box<dyn std::error::Error>> {
        let msg = serde_json::json!({
            "action": action,
            "params": params,
            "echo": self.echo.read().await.clone(),
        });
        self.sender
            .write()
            .await
            .send(Message::Text(msg.to_string()))
            .await?;
        Ok(())
    }

    pub async fn set_echo(&self, echo: String) {
        *self.echo.write().await = echo;
    }

    pub async fn send_group_msg(
        &self,
        group_id: i64,
        message: Vec<crate::Message>,
    ) -> Result<(), Box<dyn std::error::Error>> {
        self.make_api_call(
            "send_group_msg",
            serde_json::json!({
                "group_id": group_id,
                "message": message,
                "auto_escape": false,
            }),
        )
        .await?;
        Ok(())
    }

    pub async fn send_group_msg_str(
        &self,
        group_id: i64,
        message: &str,
    ) -> Result<(), Box<dyn std::error::Error>> {
        self.make_api_call(
            "send_group_msg",
            serde_json::json!({
                "group_id": group_id,
                "message": message,
                "auto_escape": true,
            }),
        )
        .await?;
        Ok(())
    }

    pub async fn send_private_msg(
        &self,
        user_id: i64,
        message: Vec<crate::Message>,
    ) -> Result<(), Box<dyn std::error::Error>> {
        self.make_api_call(
            "send_private_msg",
            serde_json::json!({
                "user_id": user_id,
                "message": message,
                "auto_escape": false,
            }),
        )
        .await?;
        Ok(())
    }

    pub async fn send_private_msg_str(
        &self,
        user_id: i64,
        message: &str,
    ) -> Result<(), Box<dyn std::error::Error>> {
        self.make_api_call(
            "send_private_msg",
            serde_json::json!({
                "user_id": user_id,
                "message": message,
                "auto_escape": true,
            }),
        )
        .await?;
        Ok(())
    }
}
