#pragma once
#include <string>

struct commands {
	std::string command;
	std::string content;
};

static void add_push(std::vector<struct commands>& command_content, struct commands name,std::string command, std::string content) {
	name.command = command;
	name.content = content;
	command_content.push_back(name);
}