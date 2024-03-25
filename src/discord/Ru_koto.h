#ifndef _RU_KOTO_H_
#define _RU_KOTO_H_
#pragma once
#include <iostream>
#include <memory>
#include <dpp/dpp.h>

namespace Rult {
	class Ru_koto {
	public:
		static void Init(const std::string config);
		static void Quit();
		static Ru_koto& GetInstance();

		~Ru_koto();

	private:
		static std::unique_ptr<Ru_koto>instance_;
		dpp::cluster ru_koto;
		//Class Init
		Ru_koto(const std::string config);
		//QwQ


		std::string Config(const std::string config, const std::string type);
	};
}
#endif