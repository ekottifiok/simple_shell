#include "shell.h"

/**
 * _putchar - prints out a character
 * @c: input character
 * Return: int on success
 */
int _putchar(int file_descriptor, char c)
{
	return (write(file_descriptor, &c, 1));
}
