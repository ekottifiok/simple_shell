#include "shell.h"

/**
 * __getline - simple implementation of the popular getline C
 * @lineptr: the pointer that carries the string to be updated
 * @n: the size of the buffer
 * @stream: the source the input
 * Return: returns a ssize_t of the
 */
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
