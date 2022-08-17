#include "shell.h"

/**
 * print_working_directory - handles the "pwd" as a builtin command
 * @env: the environment variable
 * @path: the user input of the path
 * @head: carries the location of the new additions to the env
 * @file_name: carries the file name
 * Return: 0 for success
 */
int print_working_directory(char **env, char *path __attribute__((unused)),
							list_t **head __attribute__((unused)),
							char *file_name
							)
{
	char *buffer;

	buffer = get_env_variable(env, "PWD");
	if (buffer)
	{
		_puts(buffer);
		free(buffer);
	}
	else
	{
		_puts(file_name);
	}
	return (0);
}
