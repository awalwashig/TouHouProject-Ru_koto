#ifndef _RU_KOTO_H_
#define _RU_KOTO_H_
#pragma once
#include <iostream>
#include <memory>

namespace Rult {
	class Ru_koto {
	public:
		static void Init(const std::string config);
		static void Quit();
		static Ru_koto& GetInstance();

		~Ru_koto();

	private:
		static std::unique_ptr<Ru_koto>instance_;
		Ru_koto(const std::string config);
		//QwQ
		void test(const std::string config);
	};
}
#endif