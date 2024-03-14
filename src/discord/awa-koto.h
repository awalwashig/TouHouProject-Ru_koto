#pragma once
/*
顾名思义
这就是一个专门写awa~koto的类（
*/
#include <dpp/dpp.h>
#include <atomic>
#include <utility>
#include "voice.h"

#define CMD_RESULT_BUF_SIZE 1024

class awa_koto {
private:
	dpp::cluster Ru_koto;
	std::vector<std::pair<std::string, std::string>> slashcommand;


	bool Terminal_ready = 0;
	dpp::message_create_t Terminal_event;
	std::string Terminal_content;
public:
	awa_koto(std::string token, bool st_);
	void add_slashcommand(std::string cmd, std::string content);
private:
	void load_slashcommand_read();

	void run_Terminal();
	static void Terminal(std::string Terminal_content, dpp::message_create_t Terminal_event, bool Terminal_ready);
	void discord_linux();
	void voice();
};