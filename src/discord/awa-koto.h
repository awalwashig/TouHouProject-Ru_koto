#pragma once
/*
顾名思义
这就是一个专门写awa~koto的类（
*/
#include <dpp/dpp.h>
#include <utility>

class awa_koto {
private:
	dpp::cluster Ru_koto;
public:
	awa_koto(std::string token);
	void start();
private:
	void discord_linux();
};