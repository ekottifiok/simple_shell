#include "shell.h"

/**
 * set_env_variable - sets the environment variable and if not
 * @environment: the global environment list
 * @variable: the variable that should edited
 * @value: the value to be edited in the environment
 * @head: the
 * Return: 0 for success
 */
int set_env_variable(char **environment, char *variable,
					 char *value, list_t **head)
{
	unsigned int iteration, size_env;

	for (size_env = 0; environment[size_env]; size_env++)
		;
	for (iteration = 0;
	strncmp(environment[iteration], variable, _strlen(variable));
	iteration++)
	{
		if ((iteration + 1) == size_env)
		{
			iteration++;
			break;
		}
	}
	if (iteration == size_env)
	{
		environment[iteration] = malloc(sizeof(char) *
				(_strlen(value) + _strlen(variable) + 2));
		add_node(head, iteration);
	}
	strcat(_strcpy(environment[iteration], variable), "=");
	strcat(environment[iteration], value);
	if (iteration == size_env)
		environment[iteration + 1] = NULL;
	return (0);
}
