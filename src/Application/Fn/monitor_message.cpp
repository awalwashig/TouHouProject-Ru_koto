#include "../Ru_koto.h"
namespace Rult {
	void Ru_koto::monitor_message() {
		ru_koto.on_message_create([this](const dpp::message_create_t event) {
			if (event.msg.channel_id == 1237707285074284574 && event.msg.author.id != ru_koto.me.id) {
				//ru_koto.message_create(dpp::message(event.msg.content).set_channel_id(950402907575054336));
				ru_koto.direct_message_create(1019845444311973918, dpp::message(event.msg.content));

			}
			});
	}
}