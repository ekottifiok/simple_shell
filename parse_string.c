#include "shell.h"

/**
 * parse_string - takes in a string and parses it into bits.
 * EXAMPLE: input string "Hello World I am fine"
 * RESULT:	"Hello", "World", "I", "am", "fine"
 * @str: input string
 * @delimiter: what separates a string separate
 * Return: a pointer to a pointer of the result
 */
char **parse_string(char *str, char *delimiter)
{
	int iteration, no_delimiter, k;
	char **parsed, *buffer = strdup(str), *token;

	/*
	 * calculates the number of tokens for the string
	 */
	for (iteration = 0, no_delimiter = 0, k = 0; str[iteration]; iteration++)
	{
		if (str[iteration] == *delimiter)
			no_delimiter++;
	}

	parsed = malloc(sizeof(char *) * (no_delimiter + 2));
	if (parsed == NULL)
		return (NULL);
	token = strtok(buffer, delimiter);
	while (token)
	{
		parsed[k] = malloc((_strlen(token) + 1));
		_strcpy(parsed[k++], token);
		token = strtok(NULL, delimiter);
	}
	parsed[k] = NULL;

	free(buffer);
	return (parsed);
}
