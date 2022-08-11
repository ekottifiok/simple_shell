#include "shell.h"

/**
 * get_env_variable - takes in a var and returns the result
 * from the environment
 * @env: the environment variable
 * @var: takes in variable that needs to be found
 * Return: returns the result of the environment variable
 */
char *get_env_variable(char **env, char *var)
{
	unsigned int iter, size_env;
	char *path = NULL, *buffer, *delim = "=", *result;

	for (size_env = 0; env[size_env]; size_env++)
		;

	for (iter = 0; strncmp(env[iter], var, _strlen(var)); iter++)
	{
		if ((iter + 1) == size_env)
			return (NULL);
	}
	buffer = strdup(env[iter]);
	path = strtok(buffer, delim);
	path = strtok(NULL, delim);
	result = strdup(path);
	free(buffer);
	return (result);
}
