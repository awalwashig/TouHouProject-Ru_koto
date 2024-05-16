#pragma once
#include "../../Application/Ru_koto.h"
#include "../twobot.hh"
#include "../../../dependencies/include/dpp-10.0/dpp/dpp.h"

#include<regex>
#include <stdlib.h>
#include <string_view>

namespace TwoUtilAttribute {
	using twobot::Config;
	using twobot::BotInstance;
	using twobot::ApiSet;
	using namespace twobot::Event;

	auto instance = BotInstance::createInstance(Config{
		"192.168.31.167",
		5751,
		5752,
		std::nullopt
		});
}

namespace TwoMessageUtil {
	//选择名字（）
	std::string Choice_name(const TwoUtilAttribute::GroupMsg& msg) {
		if (!msg.sender["card"].empty())
			return msg.sender["nickname"];
		else
			return msg.sender["card"];
	}

	//日后处理
	std::string Processing(const dpp::message_create_t event) {
		return event.msg.content;
	}

	//DC_使用正则表达式处理cq消息
	std::string Processing(const TwoUtilAttribute::GroupMsg& msg) {
		return msg.raw_message;
	}
}

namespace TwoSend {
	using twobot::Config;
	using twobot::BotInstance;
	using twobot::ApiSet;
	using namespace twobot::Event;
	using namespace TwoUtilAttribute;

	void botSend(const GroupMsg&& msg) {
		if (msg.raw_message.find("/") == 0)
			instance->getApiSet().sendGroupMsg(638380392, TwoMessageUtil::Processing(msg));
		else
			Rult::Ru_koto(this).message_create(dpp::message(TwoMessageUtil::Choice_name(msg) + ":" + TwoMessageUtil::Processing(msg)).set_channel_id(950402907575054336));
	});
	
	void botSend(const dpp::message_create_t& event) {
		if (event.msg.channel_id == 950402907575054336 && event.msg.author.id != this.me.id) {
			instance->getApiSet().sendGroupMsg(638380392, event.msg.author.global_name + ":" + TwoMessageUtil::Processing(event));
		}
	}
}