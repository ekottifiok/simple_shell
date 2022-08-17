#include "shell.h"

/**
 * unset_env - handles the "help" as a builtin command
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * @file_name: carries the file name
 * Return: 0 for success
 */
int unset_env(char **env, char *string, list_t **head __attribute__((unused)),
			  char *file_name __attribute__((unused)))
{
	char **data;
	unsigned int iter, size_env;

	data = parse_string(string, " ");
	for (iter = 0; data[iter]; iter++)
		;
	if (iter != 2)
	{
		fprintf(stderr, "Failed");
		return (1);
	}
	for (size_env = 0; env[size_env]; size_env++)
		;

	for (iter = 0; _strncmp(env[iter], data[1], _strlen(data[1])); iter++)
	{
		if ((iter + 1) == size_env)
		{
			fprintf(stderr, "Failed");
			return (1);
		}
	}
	for (; iter < size_env; iter++)
		env[iter] = env[iter + 1];


	return (0);
}
