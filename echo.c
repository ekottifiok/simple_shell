#include "shell.h"

/**
 * echo - prints out a string
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int echo(char **env __attribute__((unused)), char *string,
		 list_t **head __attribute__((unused)))
{
	char *buffer;

	buffer = copy_string_index(string, 5, '\0');
	fprintf(stdout, "%s\n", buffer);
	return (0);
}
