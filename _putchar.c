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
