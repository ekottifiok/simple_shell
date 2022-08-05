//
// Created by ifiokekott on 8/5/22.
//
#include "shell.h"

int execute_decision(char *string, char **environment)
{
    unsigned int iter;
    struct stat st;
    char *complete_string;
	int (*builtin_commands)(char *) = NULL;
    // Returns first path_token



    if (string[0] == '/')
    {
        if (stat(string, &st) == 0)
        {
            execute_command(parse_string(string, " "), NULL);
            return (0);
        }
    }
    else
    {
        if (complete_string = complete_path(string, environment))
        {
            execute_command(parse_string(complete_string, " "), NULL);
			free(complete_string);
            return (0);
        }
		else if (builtin_commands = get_builtin_function(string))
		{
			while (*string != ' ')
				*string++;
			*string++;
			if (!builtin_commands(string))
				return  (0);
		}

    }
    return (1);
}
