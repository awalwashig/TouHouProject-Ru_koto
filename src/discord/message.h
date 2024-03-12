#pragma once
#include <dpp/dpp.h>
#include "struct.hpp"
class base_message {
public:
	
};

/*
在OAuth2 没有完成前，暂时使用斜杠命令
注意多线程的问题，因此使用静态函数
如果要使用的话，互斥得加上（笑
*/
class message_slashcommand {
public:

	static void on_slashcommand_voice(const dpp::slashcommand_t& event);
	//请将创建的指令放在这里
	static std::vector<struct commands> get_commands();
};