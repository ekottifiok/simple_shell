#include "shell.h"

/**
 * print_working_directory - handles the "pwd" as a builtin command
 * @env: the environment variable
 * @path: the user input of the path
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int print_working_directory(char **env, char *path __attribute__((unused)),
							list_t **head __attribute__((unused)))
{
	char *buffer;

	buffer = get_env_variable(env, "PWD");
	puts(buffer);
	free(buffer);
	return (0);
}
