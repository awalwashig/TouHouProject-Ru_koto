use crate::api::ApiSet;
use crate::message::Message;
use serde::{Deserialize, Serialize};
use std::fmt::Debug;
use std::sync::Arc;

#[derive(Serialize, Deserialize, Debug)]
pub struct Sender {
    #[serde(default)]
    pub user_id: Option<i64>,

    #[serde(default)]
    pub nickname: Option<String>,

    #[serde(default)]
    pub sex: Option<String>,

    #[serde(default)]
    pub age: Option<i32>,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct GroupMsg {
    pub time: i64,

    pub self_id: i64,

    pub post_type: String,

    pub message_type: String,

    pub sub_type: String,

    pub message_id: i32,

    pub group_id: i64,

    pub user_id: i64,

    pub anonymous: Option<serde_json::Value>,

    pub message: Vec<Message>,

    pub raw_message: String,

    pub font: i32,

    pub sender: Sender,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct PrivateMsg {
    pub time: i64,

    pub self_id: i64,

    pub post_type: String,

    pub message_type: String,

    pub sub_type: String,

    pub message_id: i32,

    pub user_id: i64,

    pub message: Vec<Message>,

    pub raw_message: String,

    pub font: i32,

    pub sender: Sender,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct Heartbeat {
    pub time: i64,

    pub post_type: String,

    pub meta_event_type: String,

    pub status: String,

    pub interval: i64,

    pub self_id: i64,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct ApiResponse {
    pub status: String,
    pub retcode: i32,
    pub data: serde_json::Value,
    pub echo: String,
}

#[derive(Serialize, Deserialize, Debug)]
pub enum EventCollection {
    GroupMsg(GroupMsg),
    PrivateMsg(PrivateMsg),
    Heartbeat(Heartbeat),
    ApiResponse(ApiResponse),
    Unknown(Unknown),
}

#[derive(Serialize, Deserialize, Debug)]
pub struct Unknown {
    pub raw_json: serde_json::Value,
}

pub trait Event {}

impl Event for GroupMsg {}
impl Event for PrivateMsg {}
impl Event for Heartbeat {}
impl Event for ApiResponse {}

impl Event for Unknown {}

pub type HandlerFn = Box<dyn Fn(Box<EventCollection>, Arc<ApiSet>)>;
