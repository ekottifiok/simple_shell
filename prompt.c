#include "shell.h"

/**
 * prompt - runs what the user sees everytime the loop is ran
 * @env: the environment variable
 * Return: 0 for success
 */
int prompt(char **env __attribute__((unused)))
{
	/**
	 * char *buffer = get_env_variable(env, "PWD");
	 * printf("#cisfun$ ", buffer)
	 * free(buffer)
	 */

	printf("#cisfun$ ");
	return (0);
}
