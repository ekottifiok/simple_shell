#include "shell.h"

/**
 * _printf - prints a string
 * @str: input string
 * Return: returns an int
 */
int _printf(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (0);
}
