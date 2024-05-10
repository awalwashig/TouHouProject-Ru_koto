#include "../Ru_koto.h"

#include <stdlib.h>
namespace Rult {
	void Ru_koto::QQandDiscord() {
		ru_koto.on_message_create([this](const dpp::message_create_t event) {
			if (event.msg.channel_id == 1214243217537503283 && event.msg.author.id != ru_koto.me.id) {
				//awa(atoi(event.msg.content.c_str()));
			}
			});
	}
}