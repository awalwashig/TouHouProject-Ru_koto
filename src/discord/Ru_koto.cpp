#include "Ru_koto.h"

namespace Rult {
	void Ru_koto::Init() {
		instance_.reset(new Ru_koto);
	}

	void Ru_koto::Quit() {
		instance_.reset();
	}

	Ru_koto& Ru_koto::GetInstance() {
		return *instance_;
	}

	Ru_koto::Ru_koto(){
		test();
	}

	Ru_koto::~Ru_koto() {
		
	}
}
