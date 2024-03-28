#include "../Ru_koto.h"

namespace Rult {



	void Ru_koto::slashcommand() {
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "刷新命令") {
				std::vector<std::string> content = Config(config_, "slashcommand");
				for (int i = 0; i < content.size() / 2; ++++i) {
					std::cout << content[i] << "-" << content[++i];
					ru_koto.global_command_create(dpp::slashcommand(content[i],content[++i],ru_koto.me.id));
				}
			}
			});

		ru_koto.on_ready([this](const dpp::ready_t& event) {

			});

	}
}