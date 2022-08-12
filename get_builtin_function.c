#include "shell.h"

/**
 * get_builtin_function - gets builtin functions
 * @string: the string to be compared
 * Return: the function gotten
 */
int (*get_builtin_function(char *string))(char **, char *, list_t **)
{
	char *first_word, *delimiter = " ", *buffer;
	execute_functions functions[] = {
			{"cd", change_directory},
			{"pwd", print_working_directory},
			{"echo", echo},
			{"help", help},
			{"env", print_env},
			{NULL, NULL},
	};
	int iteration;

	buffer = strdup(string);
	first_word = strtok(buffer, delimiter);
	for (iteration = 0; functions[iteration].keyword != NULL; iteration++)
	{
		if (!strcmp(functions[iteration].keyword, first_word))
			break;
	}
	free(buffer);
	return (functions[iteration].op);
}
