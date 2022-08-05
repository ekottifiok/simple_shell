#include "main.h"

/**
 * _strlen - works like the famous strlen
 *
 * @string: string to be counted
 * Return: size_t length
 */
size_t _strlen(char *string)
{
	size_t string_len;

	for (string_len = 0; string[string_len]; string_len++)
		;

	return (string_len);
}
