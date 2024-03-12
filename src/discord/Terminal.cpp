#include "Terminal.h"

void Terminal_linux::Terminal(const char* cmd, char* result)
{
	char buf_ps[CMD_RESULT_BUF_SIZE];
	char ps[CMD_RESULT_BUF_SIZE] = { 0 };
	FILE* ptr;

	strcpy(ps, cmd);

	if ((ptr = popen(ps, "r")) != NULL)
	{
		while (fgets(buf_ps, sizeof(buf_ps), ptr) != NULL)
		{
			strcat(result, buf_ps);
			if (strlen(result) > CMD_RESULT_BUF_SIZE)
			{
				break;
			}
		}
		pclose(ptr);
		ptr = NULL;
	}
}

void Terminal_linux::Start_Thread_Terminal(const char* cmd, char* result)
{
	std::thread Terminal(Terminal_linux::Terminal, cmd, result);
}
