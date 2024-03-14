#include "awa-koto.h"

awa_koto::awa_koto(std::string token, bool st_)
	:Ru_koto(token, dpp::i_default_intents | dpp::i_message_content) {

	Ru_koto.on_log(dpp::utility::cout_logger());

	discord_linux();

	run_Terminal();

	voice();

	on_ready();

	Ru_koto.start(st_);
}



void awa_koto::run_Terminal()
{
	Ru_koto.on_message_create([this](const dpp::message_create_t event) {
		if (event.msg.channel_id == 1214243217537503283 && event.msg.author.id != Ru_koto.me.id) {
			Terminal_event = event;
			Terminal_content = event.msg.content;
			Terminal_ready = 1;
		}
		});
}

void awa_koto::Terminal(std::string Terminal_content, dpp::message_create_t Terminal_event, bool Terminal_ready) {
	{
		char* result;
		char buf_ps[CMD_RESULT_BUF_SIZE];
		char ps[CMD_RESULT_BUF_SIZE] = { 0 };
		FILE* ptr;
		while (true) {
			if (Terminal_ready == 1) {
				strcpy(ps, Terminal_content.c_str());
				if ((ptr = popen(ps, "r")) != NULL) {
					while (fgets(buf_ps, sizeof(buf_ps), ptr) != NULL)
					{
						strcat(result, buf_ps);
						if (strlen(result) > CMD_RESULT_BUF_SIZE)
						{
							break;
						}
						ptr = NULL;
					}
					Terminal_event.send(result);
				}
				Terminal_ready == 0;
			}
		}
	}
}

void awa_koto::discord_linux() {
	Ru_koto.on_slashcommand([this](const dpp::slashcommand_t event) {
		if (event.command.get_command_name() == "登录Linux") {
			event.reply("");
		}
		});
}

void awa_koto::voice() {
	Ru_koto.on_slashcommand(voice::voice_link);
}

void awa_koto::on_ready()
{
	Ru_koto.on_ready([this](const dpp::ready_t& event) {
		if (dpp::run_once<struct clear_bot_commands>()) {
			Ru_koto.global_command_create(dpp::slashcommand("登录Linux", "Send your user!", Ru_koto.me.id));
			Ru_koto.global_command_create(dpp::slashcommand("加入雅语交合", "听听你的", Ru_koto.me.id));
			Ru_koto.global_command_create(dpp::slashcommand("断开雅语交合", "润了", Ru_koto.me.id));
		}
		});
}
