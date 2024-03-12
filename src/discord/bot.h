#include "message.h"
#include "voice.h"
#include "config.hpp"
void delete_slashcommands(dpp::cluster bot) {

	bot.on_log(dpp::utility::cout_logger());

	bot.on_ready([&bot](const dpp::ready_t& event) {
		if (dpp::run_once<struct clear_bot_commands>()) {
			bot.global_bulk_command_delete();
			bot.guild_bulk_command_delete(1024692662873366598);
		}
		});

	bot.start(dpp::st_wait);
}
