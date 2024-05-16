use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Debug, Default)]
#[serde(tag = "type", content = "data")]
pub enum Message {
    #[serde(rename = "text")]
    Text { text: String },

    #[serde(rename = "face")]
    Face { id: i32 },

    #[serde(rename = "image")]
    Image { file: String },

    #[serde(rename = "record")]
    Record { file: String },

    #[serde(rename = "video")]
    Video { file: String },

    #[serde(rename = "at")]
    At { qq: i64 },

    #[serde(rename = "rps")]
    Rps {},

    #[serde(rename = "dice")]
    Dice {},

    #[serde(rename = "shake")]
    Shake {},

    #[serde(rename = "poke")]
    Poke {
        #[serde(rename = "type")]
        _type: String,
        id: String,
    },

    #[serde(rename = "share")]
    Share {
        url: String,
        title: String,
        content: String,
        image: String,
    },

    #[serde(rename = "contact")]
    Contact {
        id: String,
        #[serde(rename = "type")]
        _type: String,
    },

    #[serde(rename = "location")]
    Location {
        lat: f64,
        lon: f64,
        title: Option<String>,
        content: Option<String>,
    },

    #[serde(rename = "music")]
    Music {
        #[serde(rename = "type")]
        _type: String,
        id: Option<String>,
        url: Option<String>,
        title: Option<String>,
        audio: Option<String>,
        content: Option<String>,
        image: Option<String>,
    },

    #[serde(rename = "reply")]
    Reply { id: String },

    #[serde(rename = "forward")]
    Forward { id: String },

    #[serde(rename = "node")]
    Node {
        id: Option<String>,
        user_id: Option<String>,
        nickname: Option<String>,
        content: Option<Vec<Message>>,
    },

    #[serde(rename = "xml")]
    Xml { data: String },

    #[serde(rename = "json")]
    Json { data: String },
    #[default]
    Unknown,
}
