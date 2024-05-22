#include "../../Application/Ru_koto.h"
#include "../twobot.hh"
//#include "../../../dependencies/include/dpp-10.0/dpp/dpp.h"
#include<regex>
#include <stdlib.h>
#include <string_view>
#include "Two_link_QD.hpp"

//----main----
namespace Rult {
	using twobot::Config;
	using twobot::BotInstance;
	using twobot::ApiSet;
	using namespace twobot::Event;
	using namespace TwoUtilAttribute;

	void Ru_koto::QDSand() {
		ru_koto.on_message_create([&](const dpp::message_create_t event) {
			if (event.msg.channel_id == 950402907575054336 && event.msg.author.id != ru_koto.me.id) {
				instance->getApiSet().sendGroupMsg(638380392, event.msg.author.global_name + ":" + TwoMessageUtil::Processing(event));
			}
			});

		//QQ发送消息给DC
		instance->onEvent<GroupMsg>([&](const GroupMsg& msg) {
			if (msg.raw_message.find("/") == 0) {
				instance->getApiSet().sendGroupMsg(638380392, TwoMessageUtil::Processing(msg));
			}
			else {
				ru_koto.message_create(dpp::message(TwoMessageUtil::Choice_name(msg) + ":" + TwoMessageUtil::Processing(msg)).set_channel_id(950402907575054336));
			}
			});

		std::thread([&]() {
			instance->start();
			}).detach();
	}
}