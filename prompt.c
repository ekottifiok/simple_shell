#include "shell.h"

/**
 * prompt - runs what the user sees everytime the loop is ran
 * @env: the environment variable
 * Return: 0 for success
 */
int prompt(char **env)
{
	char *buffer = get_env_variable(env, "PWD");

	printf("%s $ ", buffer);
	free(buffer);
	return (0);
}
