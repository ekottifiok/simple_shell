//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

char *get_env_variable(char **environment, char *variable)
{
	unsigned int iteration;
	char *path = NULL, *buffer, *delimiter = "=", *result;

	for (iteration = 0; strncmp(environment[iteration], variable, strlen(variable)); iteration++)
		;
	buffer =  strdup(environment[iteration]);
	path = strtok(buffer, delimiter);
	path = strtok(NULL, delimiter);
	result = strdup(path);
	free(buffer);
	return (result);
}