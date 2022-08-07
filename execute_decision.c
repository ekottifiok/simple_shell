//
// Created by ifiokekott on 8/5/22.
//
#include "shell.h"

int execute_decision(char *string, char **environment, list_t **head)
{
	unsigned int iter;
	struct stat st;
	char *complete_string, **parsed_string;
	int (*builtin_commands)(char **, char *, list_t **) = NULL;
	// Returns first path_token

	if (string[0] == '/')
	{
		if (stat(string, &st) == 0)
		{
			parsed_string = parse_string(string, " ");
			execute_command(parsed_string, NULL);
			free_double_pointer(parsed_string);
			return (0);
		}
	}
	else
	{
		if (builtin_commands = get_builtin_function(string))
		{
			if (!builtin_commands(environment, string, head))
				return (0);
		}
		else if (complete_string = complete_path(string, environment))
		{
			parsed_string = parse_string(complete_string, " ");
			execute_command(parsed_string, NULL);
			free(complete_string);
			free_double_pointer(parsed_string);
			return (0);
		}
	}
	return (1);
}
