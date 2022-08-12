#include "shell.h"

/**
 * _putchar - prints out a character
 * @c: input character
 * Return: int on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints a string
 * @param str
 * @param ...
 */
int _printf(char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (0);
}