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
private:
	void read_token();
	std::vector<std::pair<std::string, std::string>> read_slashcommand();
};
//在调用config时就将设定填满,没有的返回 -1 
config::config()
{
	read_token();
}

void config::read_token() {
	std::ifstream stream("/home/awalwa/projects/bot/config.txt");
	std::string line;
	while (getline(stream, line)) {
		if (line.find("#token") != std::string::npos) {
			getline(stream, line);
			token = line;
		}
	}
}

inline std::vector<std::pair<std::string, std::string>> config::read_slashcommand() {
	std::ifstream stream("/home/awalwa/projects/bot/slashcommand.txt");
	std::string line;
	std::vector<std::pair<std::string, std::string>> cmd_content;
	std::string tmp;
	while (getline(stream, line)) {
		tmp = line;
		getline(stream, line);
		cmd_content.push_back(std::pair<std::string, std::string>() = { tmp,line });
	}
	return cmd_content;
}
