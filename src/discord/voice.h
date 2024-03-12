#pragma once
#include <dpp/dpp.h>

class voice {
public:
	static void voice_link(const dpp::slashcommand_t& event);
	static void voice_break_link(const dpp::slashcommand_t& event);

	static void on_slashcommand_voice(const dpp::slashcommand_t& event);

};