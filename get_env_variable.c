//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

char *get_env_variable(char **environment, char *variable)
{
	unsigned int iteration, size_env;
	char *path = NULL, *buffer, *delimiter = "=", *result;

	for (size_env = 0; environment[size_env]; size_env++)
		;

	for (iteration = 0; strncmp(environment[iteration], variable, strlen(variable)); iteration++)
	{
		if ((iteration+1) == size_env)
			return (NULL);
	}
	buffer = strdup(environment[iteration]);
	path = strtok(buffer, delimiter);
	path = strtok(NULL, delimiter);
	result = strdup(path);
	free(buffer);
	return (result);
}
