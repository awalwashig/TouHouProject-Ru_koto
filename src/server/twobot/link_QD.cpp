#include "../../Application/Ru_koto.h"
#include "../twobot.hh"
#include "../../../dependencies/include/dpp-10.0/dpp/dpp.h"
#include<regex>
#include <stdlib.h>
#include <string_view>
#include "Two_link_QD.hpp"

//----main----
namespace Rult {
	using namespace TwoUtilAttribute;

	void Ru_koto::QDSand() {
		ru_koto.on_message_create([&](const dpp::message_create_t event) {
			TwoSend::botSend(event);
			});

		//QQ发送消息给DC
		instance->onEvent<GroupMsg>([&](const GroupMsg& msg) {
			TwoSend::botSend(msg);
			});

		std::thread([&]() {
			instance->start();
			}).detach();
	}
}