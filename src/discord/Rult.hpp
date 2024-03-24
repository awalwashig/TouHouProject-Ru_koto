
#include "Ru_koto.h"

namespace Rult {
	std::unique_ptr<Ru_koto> Ru_koto::instance_ = nullptr;

	void Init() {
		Ru_koto::Init();
	}
	void Quit() {
		Ru_koto::Quit();
	}
	
	
}