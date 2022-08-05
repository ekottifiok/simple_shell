#include "main.h"

void (*default_actions(char *string))(list_type *)
{
	builtins_t mappings[] = {
		{"break", print_list},
		{"history", print_list},
		{NULL, NULL},
	};
	size_t i;

	for (i = 0; mappings[i].run != NULL; i++)
	{
		if (_strcmp(string, mappings[i].string) == _strlen(mappings[i].string))
			return (mappings[i].run);
	}
	return (NULL);
}
