#include "shell.h"

/**
 * execute_command - executes the command
 * @arguments: an array of arguments
 * @environment: the global environment variable
 * Return: 0 success and 1 failure
 */
int execute_command(char *arguments[], char **environment)
{
	pid_t pid;
	int status;
	char *sh = "trial";

	pid = fork();
	if (pid == -1)
	{
		if (!isatty(STDIN_FILENO))
			perror(sh);
		return (1);
	}

	else if (pid == 0)
	{
		if ((execve(arguments[0], arguments, environment)) == -1)
		{
			if (!isatty(STDIN_FILENO))
				perror(sh);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			if (status == 126)
				puts("Permission Denied");
		}
	}
}
