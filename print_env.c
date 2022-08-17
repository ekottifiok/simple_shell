#include "shell.h"

/**
 * print_env - handles the "env" as a builtin command
 * prints the env
 * @env: the environment variable
 * @path: the user input string
 * @head: carries the location of the new additions to the env
 * @file_name: carries the file name
 * Return: 0 for success
 */
int print_env(char **env, char *path __attribute__((unused)),
			  list_t **head  __attribute__((unused)),
			  char *file_name)
{
	if (print_double_pointer(env))
		puts(file_name);
	return (0);
}
