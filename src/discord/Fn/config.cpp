#include "../Ru_koto.h"
#include <fstream>

namespace Rult {
	std::string Ru_koto::Config(const std::string config, const std::string type) {
		std::ifstream stream(config);
		std::string line;

		if (type == "token")
			while (getline(stream, line)) {
				if (line.find("#token") != std::string::npos) {
					getline(stream, line);
					return line;
				}
			}


	}
}