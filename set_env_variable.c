//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

int set_env_variable(char **environment, char *variable, char *value, list_t **head)
{
	unsigned int iteration, size_env;
	char *modified_value;

	for (size_env = 0; environment[size_env]; size_env++)
		;
	for (iteration = 0; strncmp(environment[iteration], variable, strlen(variable)); iteration++)
	{
		if ((iteration+1) == size_env)
		{
			iteration++;
			break;
		}
	}
	if (iteration == size_env) {
		environment[iteration] = malloc(sizeof(char) * (strlen(value) + strlen(variable) + 2));
		add_node(head, iteration);
	}
	strcat(strcpy(environment[iteration], variable), "=");
	strcat(environment[iteration], value);
	if (iteration == size_env)
		environment[iteration+1] = NULL;
	return (0);
}