#include "../Ru_koto.h"

namespace Rult {

	int awa = 0;

	bool flag = false;

	std::string command = "";

	void linux(dpp::snowflake Login) {
		bool flag = false;
		while (!flag) {
			
		}

	}

	void Ru_koto::monitor_message() {
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "登录linux") {

			}
			});

		//开始监测消息
		ru_koto.on_message_create([this](const auto& event) {
			if (flag) {

			}
			});
	}
}