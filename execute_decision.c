#include "shell.h"

/**
 * execute_decision - decides what action to be carried out
 * @string: the user input string
 * @environment: environment variable
 * @head: the head list carries the changes to environment
 * Return: 0 success
 */
int execute_decision(char *string, char **environment, list_t ***head)
{
	struct stat st;
	char *complete_string, **parsed_string;
	int (*builtin_commands)(char **, char *, list_t **) = NULL;
	/*
	 * Returns first path_token
	 */

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
		builtin_commands = get_builtin_function(string);

		if (builtin_commands)
		{
			if (!builtin_commands(environment, string, *head))
				return (0);
		}
		complete_string = complete_path(string, environment);
		if (complete_string)
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
