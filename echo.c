#include "shell.h"

/**
 * echo - prints out a string
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int echo(char **env, char *string,
		 list_t **head __attribute__((unused)))
{
	char *buffer1, *buffer2, *buffer3;

	buffer1 = copy_string_index(string, 1, " ");
	if (*buffer1 == '$')
	{
		buffer3 = copy_string_index(buffer1, 1, "$");
		if (_strcmp(buffer3, "$"))
		{
			free(buffer3);
			buffer3 = strdup("MANAGERPID");
		}
		buffer2 = get_env_variable(env, buffer3);
		free(buffer1);
		free(buffer3);
		buffer1 = buffer2;
	}
	fprintf(stdout, "%s\n", buffer1);
	free(buffer1);
	return (0);
}
