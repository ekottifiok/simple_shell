#include "main.h"

void run_command(char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		printf("failed to create a child\n");
	}
	else if (pid == 0)
	{

		execvp(argv[0], argv);
	}
}
