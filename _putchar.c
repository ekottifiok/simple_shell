#include "shell.h"

/**
 * _putchar - prints out a character
 * @c: input character
 * * @file_descriptor: carries which output the file should go
 * Return: int on success
 */
int _putchar(int file_descriptor, char c)
{
	return (write(file_descriptor, &c, (size_t)1));
}
