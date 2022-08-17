#include "shell.h"

/**
 * _puts - prints a string without adding the newline character
 * @str: input string to be printed
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(STDOUT_FILENO, str[i]);
		i++;
	}
	_putchar(STDOUT_FILENO, '\n');

}
