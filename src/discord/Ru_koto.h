#ifndef _RU_KOTO_H_
#define _RU_KOTO_H_
#pragma once
#include <dpp/dpp.h>

namespace Rult {
	//使用3D
	class Ru_koto {
	public:
		static void Init(const std::string config);
		static void Quit();
		static Ru_koto& GetInstance();

		~Ru_koto();

		std::string config_;
	private:
		static std::unique_ptr<Ru_koto>instance_;
		dpp::cluster ru_koto;
		//Class Init
		Ru_koto(const std::string config);

		//Fn

		std::vector<std::string> Config(const std::string config, const std::string type);
		

		void slashcommand();
		void voice();
		void monitor_message();
		void terminal();

	};
}
#endif