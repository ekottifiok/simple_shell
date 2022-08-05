//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

int (*get_builtin_function(char *string))(char *)
{
	char *first_word, *delimiter = " ";
	execute_functions functions[] = {
			{"cd", change_directory},
			{NULL, NULL},
	};
	int (*builtin_commands)(char *) = NULL, iteration;

	first_word = strtok(strdup(string), delimiter);
	for (iteration = 0; functions[iteration].keyword != NULL; iteration++)
	{
		if (!strcmp(functions[iteration].keyword, first_word))
			break;
	}
	return (functions[iteration].op);
}