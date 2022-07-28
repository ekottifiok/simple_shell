#include "main.h"

/**
 * _strcmp - prints a string, in reverse, followed by a new line..
 * @duplicate: input integer.
 * @original: input integer
 * Return: no return.
 */

size_t _strcmp(char *duplicate, char *original)
{
	size_t iteration = 0;

	if (!duplicate || !original)
		return (0);
	while (*duplicate && (*duplicate++ == *original++))
	{
		iteration++;
	}

	return (iteration);
}
