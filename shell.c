//
// Created by ifiokekott on 8/4/22.
//
#include "shell.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
    char *user_input = NULL;
    size_t max_len = BUFSIZ;

    while (1)
    {
        prompt(env);
        getline(&user_input, &max_len, stdin);
        // removes the new line at the end of the string
        user_input[strlen(user_input) - 1] = '\0';
        if (!strcmp(user_input, "exit") || *user_input == '\0')
            break;

        if (execute_decision(user_input, env))
            printf("Command '%s' not found\n", user_input);
    }
    free(user_input);
    return (0);
}

