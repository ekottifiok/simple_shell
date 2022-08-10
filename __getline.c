#include "shell.h"

ssize_t __getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t count;
	char c = 0;

	if (*n == 0)
		return (-1);

	*lineptr = malloc(sizeof(char));
	for (count = 0; c != '\n' && count < *n - 1; count++)
	{
		c = (char)getc(stream);
		if (c == EOF)
		{
			if (count == 0)
				return (-1);
			break;
		}
		(*lineptr)[count] = c;
		*lineptr = realloc(*lineptr, count + 3);
	}
	(*lineptr)[count] = '\0';

	return ((ssize_t)count);
}
