#include "shell.h"

/**
 * copy_string_index - copies a string based on the index
 * either a character or index
 * @string: the string to be copied
 * @start: the index to start
 * @find: the character to start the copy
 * Return: it returns a copy of the string
 */
char *copy_string_index(char *string, unsigned int start, char *find)
{
	size_t iter, size_string, diff;
	char *buffer;

	size_string = strlen(string);
	if ((!start && !find) || start >= size_string)
		return (NULL);
	if (find)
	{
		for (iter = 0; iter < size_string; iter++)
		{
			if (string[iter] == *find)
			{
				if (string[iter + 1] == *find)
					continue;
				break;
			}
		}
		if (iter == size_string)
			return (NULL);
		start += iter;
	}
	diff = size_string - start;
	buffer = malloc(sizeof(char) * (diff + 1));
	for (iter = 0; iter < diff; iter++, start++)
	{
		buffer[iter] = string[start];
	}
	buffer[iter] = '\0';

	return (buffer);
}
