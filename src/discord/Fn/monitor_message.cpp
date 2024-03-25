#include "../Ru_koto.h"

namespace Rult{
	void test() {
		while (1)
			std::cout << "OwO-\n";
	}
	void Ru_koto::monitor_message() {
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "登录linux") {
				std::cout << "::::";
				while (1)
					std::cout << "qwq";
			}
			});

	}
}