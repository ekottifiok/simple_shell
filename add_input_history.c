#include "shell.h"

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