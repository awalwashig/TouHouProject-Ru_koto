#ifndef _RU_KOTO_H_
#define _RU_KOTO_H_
#pragma once

#include <iostream>
#include <vector>
#include <queue>
/*
该类主要设计成为多个框架提供传递的方法
目前来说是这样的
*/
namespace RuKoto {
	//
	class UniversalContent;
	class Config;
	class Message;
	class Command;
}

class RuKoto::UniversalContent {

private:

};

class RuKoto::Config {
public:
	void SetUniversalContent(UniversalContent* m_class);
private:
	RuKoto::UniversalContent* m_UniversalContent;
};
#endif // !RU_KOTO_H