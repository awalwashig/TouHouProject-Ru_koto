#pragma once
#include <twobot.hh>

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