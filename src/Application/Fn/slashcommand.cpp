#include "../Ru_koto.h"

namespace Rult {
	void Ru_koto::slashcommand() {
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "刷新命令") {
				ru_koto.global_bulk_command_delete();
				std::vector<std::string> content = Config(config_, "slashcommand");
				for (int i = 0; i < content.size() - 1; ++++i) {
					std::cout << content[i] << "-" << content[++i];
					ru_koto.global_command_create(dpp::slashcommand(content[i], content[++i], ru_koto.me.id));
				}
			}
			});
		
		ru_koto.on_ready([this](const dpp::ready_t& event) {
			ru_koto.global_command_create(dpp::slashcommand("刷新命令", "Refresh command", ru_koto.me.id));
			});

	}
}