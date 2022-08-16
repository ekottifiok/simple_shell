#include "shell.h"

/**
 * _puts - prints a string without adding the newline character
 * @str: input string to be printed
 */
void _puts(int file_descriptor, char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(file_descriptor, str[i]);
		i++;
	}

}
