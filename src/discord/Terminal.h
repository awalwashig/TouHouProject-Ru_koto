#pragma once
#include <dpp/dpp.h>
#include <vector>
#include <string>
#include <stdio.h>
#define CMD_RESULT_BUF_SIZE 1024

class Terminal_linux {
public:

	static void Terminal(const char* cmd, char* result);
	static void Start_Thread_Terminal(const char* cmd, char* result);
};