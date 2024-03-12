#pragma once
#include <dpp/dpp.h>
#include "struct.hpp"

class voice {
public:
	static void voice_link(const dpp::slashcommand_t& event);
	static void voice_break_link(const dpp::slashcommand_t& event);

	static void on_slashcommand_voice(const dpp::slashcommand_t& event);
	//请将创建的指令放在这里
	static std::vector<struct commands> get_commands();
};