#include "awa-koto.h"

awa_koto::awa_koto(std::string token)
	:Ru_koto(token, dpp::i_default_intents | dpp::i_message_content) {

}

void awa_koto::start() {
	slashcommand.push_back("Login to Linux");

	Ru_koto.on_log(dpp::utility::cout_logger());

	//discord_linux();

	on_ready();

	Ru_koto.start(dpp::st_wait);
}



void awa_koto::run_Terminal(dpp::cluster Ru_koto)
{

}

void awa_koto::Terminal(const char* cmd, char* result) {
	{
#define CMD_RESULT_BUF_SIZE 1024
		char buf_ps[CMD_RESULT_BUF_SIZE];
		char ps[CMD_RESULT_BUF_SIZE] = { 0 };
		FILE* ptr;

		strcpy(ps, cmd);

		if ((ptr = popen(ps, "r")) != NULL)
		{
			while (fgets(buf_ps, sizeof(buf_ps), ptr) != NULL)
			{
				strcat(result, buf_ps);
				if (strlen(result) > CMD_RESULT_BUF_SIZE)
				{
					break;
				}
			}
			pclose(ptr);
			ptr = NULL;
		}
	}
}

//void awa_koto::discord_linux() {
//	Ru_koto.on_slashcommand([=](const dpp::slashcommand_t event) {
//		if (event.command.get_command_name() == slashcommand[0]) {
//			//std::thread([=]() {
//			//	while (1) {
//			//		Ru_koto.on_message_create([=](const dpp::message_create_t event) {
//			//			Ru_koto.on_message_create([=](const dpp::message_create_t event) {
//			//				if (event.msg.author.id != Ru_koto.me.id) {
//			//					if (event.msg.channel_id == 1214243217537503283) {
//			//						event.send("awa");
//			//					}
//			//				}
//			//				});
//			//			});
//			//	}
//			//	}).detach();
//		}
//		});
//}

void awa_koto::on_ready()
{
	Ru_koto.on_ready([=](const dpp::ready_t& event) {
		if (dpp::run_once<struct register_bot_commands>()) {

			/* Create a new global command once on ready event */
			Ru_koto.global_command_create(dpp::slashcommand("Login to Linux", "discord linux()", Ru_koto.me.id));
		}
		});
}
