#include "shell.h"

/**
 * set_env - handles the "help" as a builtin command
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int set_env(char **env, char *string, list_t **head
) {
	char **data;
	unsigned int iter;

	data = parse_string(string, " ");
	for (iter = 0; data[iter]; iter++)
		;
	if (iter != 3)
	{
		free_double_pointer(data);
		return (1);
	}
	set_env_variable(env, data[1], data[2], head);
	free_double_pointer(data);
	return (0);
}
