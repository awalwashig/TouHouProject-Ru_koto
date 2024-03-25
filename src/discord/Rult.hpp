#include "Ru_koto.h"

namespace Rult {
	std::unique_ptr<Ru_koto> Ru_koto::instance_ = nullptr;
	//之后的一些初始做扩展空间
	void Init(const std::string config) {
		Ru_koto::Init(config);
	}
	void Quit() {
		Ru_koto::Quit();
	}
	
	
}