#include "shell.h"

/**
 * execute_decision - decides what action to be carried out
 * @string: the user input string
 * @environment: environment variable
 * @head: the head list carries the changes to environment
 * @file_name: carries the file name
 * Return: 0 success
 */
int execute_decision(char *string, char **environment,
					 list_t ***head, char *file_name)
{
	struct stat st;
	char *buffer1, *buffer2, *complete_string, *delimiter = " ", **parsed_string;
	int (*builtin_commands)(char **, char *, list_t **, char *) = NULL,
	success_fail = 0;

	builtin_commands = get_builtin_function(string);
	if (builtin_commands)
	{
		if (!builtin_commands(environment, string, *head, file_name))
			return (0);
	}
	else if (string[0] == '/' || (string[0] == '.' && string[1] == '/'))
	{
		buffer2 = _strdup(string);
		buffer1 = strtok(buffer2, delimiter);
		if (stat(buffer1, &st) == 0)
		{
			parsed_string = parse_string(string, " ");
			if (execute_command(parsed_string, environment))
				success_fail = 1;
			free_double_pointer(parsed_string);
		}
		free(buffer2);
	}
	else
	{
		complete_string = complete_path(string, environment);
		if (complete_string)
		{
			parsed_string = parse_string(complete_string, " ");
			if (execute_command(parsed_string, environment))
				success_fail = 1;
			free(complete_string);
			free_double_pointer(parsed_string);
			return (0);
		}
		success_fail = 1;
	}
	return (success_fail);
}
