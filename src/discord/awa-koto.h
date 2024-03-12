#pragma once
/*
顾名思义
这就是一个专门写awa~koto的类（
*/
#include <dpp/dpp.h>
#include <utility>

class awa_koto {
private:
	dpp::cluster Ru_koto;
	std::vector<std::string> slashcommand;

	bool flag;
public:
	awa_koto(std::string token);
	void start();
private:
	static void run_Terminal(dpp::cluster Ru_koto);
	void Terminal(const char* cmd, char* result);
	void discord_linux();
	void on_ready();
};