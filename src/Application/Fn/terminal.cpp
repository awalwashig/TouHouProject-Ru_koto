#include "../Ru_koto.h"

#include<cstdlib>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

namespace Rult {
	namespace Fn_private {
		inline bool objs_chan(std::vector<dpp::snowflake> objs, dpp::snowflake event) {
			for (dpp::snowflake obj : objs) if (obj == event) return true;
		}
		int objs_find(std::vector<dpp::snowflake> objs, dpp::snowflake event) {
			int i = 0;
			for (dpp::snowflake obj : objs)
				if (obj == event) return i;
				else i++;
		}
		//---Linux---but is wsl---
		std::string path = "/";

		void terminal_(std::string cmd, char* result) {
			char line[300];
			std::FILE* ptr;
			std::stringstream ss;

			char buf_ps[1024 * 9];
			char ps[1024 * 9] = { 0 };

			cmd = "cd " + path + ";" + cmd;

			strcpy(ps, cmd.c_str());

			if ((ptr = popen(ps, "r")) != NULL)
			{
				while (fgets(buf_ps, sizeof(buf_ps), ptr) != NULL)
				{
					strcat(result, buf_ps);
					if (strlen(result) > 1024 * 9)
					{
						break;
					}
				}
				pclose(ptr);
				ptr = NULL;
			}
			else
			{
				printf("popen %s error\n", ps);
			}
		}
	}

	void Ru_koto::terminal() {
		/*ru_koto.on_message_create([this](const dpp::message_create_t event) {
			if (event.msg.author != ru_koto.me.id && Fn_private::objs_chan(objs[TERMINAL_NUM], event.msg.channel_id)) {
				char result[1024 * 9] = { 0 };
				Fn_private::terminal_(event.msg.content, result);
				event.send(result);
			}
			});
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t event) {
			if (event.command.get_command_name() == "登录服务之术") {
				if (!Fn_private::objs_chan(objs[TERMINAL_NUM], event.command.channel_id)) {
					objs[TERMINAL_NUM].push_back(event.command.channel_id);
					event.reply("okey");
				}
				else event.reply("Not work, channel is listenning");
			}
			if (event.command.get_command_name() == "卸载服务之术") {
				if (Fn_private::objs_chan(objs[TERMINAL_NUM], event.command.channel_id)) {
					objs[TERMINAL_NUM].erase(objs[TERMINAL_NUM].begin() + Fn_private::objs_find(objs[TERMINAL_NUM], event.command.channel_id));
					event.reply("okey");
				}
				else event.reply("Not work,It seems that there is no");
			}
			});*/
	}
}