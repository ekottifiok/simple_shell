#include "shell.h"

/**
 * _printf - prints a string
 * @str: input string
 */
void _printf(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(STDOUT_FILENO, str[i]);
		i++;
	}
}
