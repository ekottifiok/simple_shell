//
// Created by ifiokekott on 8/4/22.
//
#include "shell.h"

int execute_command(char *arguments[], char **environment)
{
    pid_t pid;
    int status;
    char *sh = "trial";

    pid = fork();
    if (pid == -1)
    {
        perror(sh);
        return (1);
    }

    else if (pid == 0)
    {
        if ((execve(arguments[0], arguments, environment)) == 0)
            exit(0);

        perror(sh);
        exit(1);

    }
    else
    {
        waitpid(-1, &status, 0);
        return (WEXITSTATUS(status));
    }
}