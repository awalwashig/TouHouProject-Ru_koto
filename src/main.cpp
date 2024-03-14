#include "discord/awa-koto.h"
#include "discord/config.hpp"
//main内主要运行on_Fn的函数popen

int main() {
	config Ru_config;
	awa_koto Ru_koto(Ru_config.get_token(), dpp::st_wait);
}