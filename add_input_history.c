#include "shell.h"

/**
 * add_input_history - adds a new item to the history database
 * @history: the global history database
 * @string: the new string hoping to be added
 * Return: 0 success and 1 failure
 */
int add_input_history(char ****history, char *string)
{
	unsigned int iter = 0;


	if (!(**history))
	{
		**history = malloc(sizeof(char *) * 2);
	}
	else
	{
		for (; (**history)[iter]; iter++)
			;
		**history = realloc(**history, sizeof(char *) * (iter + 2));
	}


	(**history)[iter++] = strdup(string);
	(**history)[iter] = NULL;

	return (0);
}
