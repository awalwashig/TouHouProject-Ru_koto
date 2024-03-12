#pragma once
#include <string>
#include <fstream>

//初始设定
class config {
private:
	std::string token;
public:
	config();
	std::string get_token()const {
		return token;
	}
};
//在调用config时就将设定填满,没有的返回 -1 
config::config()
{
	std::ifstream stream("/home/awalwa/projects/bot/config.txt");
	std::string line;
	while (getline(stream, line)) {
		if (line.find("#token") != std::string::npos) {
			getline(stream, line);
			token = line;
		}
	}
}