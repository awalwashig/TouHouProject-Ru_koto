#include "../Ru_koto.h"

namespace Rult {
	void Ru_koto::voice(){
		ru_koto.on_slashcommand([this](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "加入雅语交合") {
				dpp::guild* g = dpp::find_guild(event.command.guild_id);

				auto current_vc = event.from->get_voice(event.command.guild_id);
				bool join_vc = true;

				if (current_vc) {
					auto user_vc = g->voice_members.find(event.command.get_issuing_user().id);

					if (user_vc != g->voice_members.end() && current_vc->channel_id == user_vc->second.channel_id) {
						join_vc = false;
					}
					else {
						event.from->disconnect_voice(event.command.guild_id);
						join_vc = true;
					}
				}

				if (join_vc) {
					if (!g->connect_member_voice(event.command.get_issuing_user().id)) {
						event.reply(dpp::message("你似乎不在语音频道").set_flags(dpp::m_ephemeral));
						return;
					}
					event.reply(dpp::message("加入语音频道ing").set_flags(dpp::m_ephemeral));
				}
				else {
					event.reply(dpp::message("我已经和你在一个语音频道了").set_flags(dpp::m_ephemeral));
				}
			}
			if (event.command.get_command_name() == "断开雅语交合") {

			}
			});
	}
}