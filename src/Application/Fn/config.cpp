#include "../Ru_koto.h"
#include <fstream>

namespace Rult {
	std::vector<std::string> Ru_koto::Config(const std::string config, const std::string type) {
		std::ifstream stream(config);
		std::string line;
		bool flag = 0;
		std::vector<std::string> content;

		while (getline(stream, line)) {
			if (line.find("#" + type) != std::string::npos) {
				while (getline(stream, line)) {
					if (!line.find("#end")) {
						return content;
					}
					content.push_back(line);
				}
			}
		}
		throw - 1;
	}
}