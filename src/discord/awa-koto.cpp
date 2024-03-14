#include "awa-koto.h"

awa_koto::awa_koto(std::string token, bool st_)
	:Ru_koto(token, dpp::i_default_intents | dpp::i_message_content) {

	Ru_koto.on_log(dpp::utility::cout_logger());

	voice();

	run_Terminal();

	discord_linux();

	Ru_koto.start(st_);
}

void awa_koto::add_slashcommand(std::string cmd, std::string content) {
	std::pair<std::string, std::string> slashcommand_tmp = { cmd,content };
	slashcommand.push_back(slashcommand_tmp);
}

void awa_koto::load_slashcommand_read() {
	Ru_koto.on_ready([this](const dpp::ready_t& event) {
		if (dpp::run_once<struct clear_bot_commands>()) {
			for (auto cmd_content : slashcommand)
				Ru_koto.global_command_create(dpp::slashcommand(cmd_content.first, cmd_content.second, Ru_koto.me.id));
		}
		});
}



void awa_koto::run_Terminal()
{
	Ru_koto.on_message_create([this](const dpp::message_create_t event) {
		if (event.msg.channel_id == 1214243217537503283 && event.msg.author.id != Ru_koto.me.id) {
			if (Terminal_ready == 1) {
				Terminal_content = event.msg.content;
			}
			else {
				Terminal_event = event;
				Terminal_ready = 1;
			}
		}
		});
}

void awa_koto::Terminal(std::string Terminal_content, dpp::message_create_t Terminal_event, bool Terminal_ready) {

}

void awa_koto::discord_linux() {
	Ru_koto.on_slashcommand([this](const dpp::slashcommand_t event) {
		if (event.command.get_command_name() == "登录服务之术") {
			event.reply("OwO");
		}
		});
}

void awa_koto::voice() {
	Ru_koto.on_slashcommand(voice::voice_link);
}