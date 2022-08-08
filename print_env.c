#include "shell.h"

/**
 * print_env - handles the "env" as a builtin command
 * prints the env
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int print_env(char **env, char *string, list_t **head)
{
	print_double_pointer(env);
	return (0);
}
