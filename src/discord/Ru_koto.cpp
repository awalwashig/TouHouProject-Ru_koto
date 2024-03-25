#include "Ru_koto.h"

namespace Rult {
	void Ru_koto::Init(const std::string config) {
		instance_.reset(new Ru_koto(config));
	}

	void Ru_koto::Quit() {
		instance_.reset();
	}

	Ru_koto& Ru_koto::GetInstance() {
		return *instance_;
	}

	Ru_koto::Ru_koto(const std::string config){
		test(config);
	}

	Ru_koto::~Ru_koto() {
		
	}
}
