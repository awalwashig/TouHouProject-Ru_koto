use url::{ParseError, Url};

#[derive(Debug)]
pub struct Config {
    pub host: String,
    pub port: u16,
    pub token: Option<String>,
}

#[allow(dead_code)]
impl Config {
    pub fn to_url(&self) -> Result<Url, ParseError> {
        let url = format!("ws://{}:{}/", self.host, self.port);
        Url::parse(&url)
    }

    pub fn token(&self) -> Option<String> {
        self.token.clone()
    }
}
