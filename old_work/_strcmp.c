#include "main.h"

/**
 * _strcmp - prints a string, in reverse, followed by a new line..
 * @duplicate: input integer.
 * @original: input integer
 * Return: no return.
 */

size_t _strcmp(char *duplicate, char *original)
{
	size_t iteration = 0, len_dup, len_orig;

	if (!duplicate || !original)
		return (-1);
	len_dup = _strlen(duplicate);
	len_orig = _strlen(original);
	if (len_dup < len_orig || len_orig < len_dup)
		return (-1);

	while (*duplicate && (*duplicate++ == *original++))
	{
		iteration++;
	}

	return (iteration);
}
