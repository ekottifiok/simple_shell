#include "shell.h"

/**
 * remove_whitespace - to remove whitespace in front of string
 * @string: user input string
 * Return: better string but must be freed
 */
char *remove_whitespace(char *string)
{
	char *new;
	unsigned int i = 0, j = 0, len_buffer = 0;


	len_buffer = strlen(string);
	for (i = 0, j = 0; string[i] == ' '; i++)
	;
	new = malloc(sizeof(char) * ((len_buffer - i) + 1));
	for (j = 0; string[i]; j++, i++)
		new[j] = string[i];
	new[j] = '\0';

	return (new);
}
