#include "shell.h"

/**
 * print_double_pointer - prints out the contents of a double pointer
 * with iteration starting with zero
 * @double_ptr: input double pointer
 * Return: 0 is success;
 */
int print_double_pointer(char **double_ptr)
{
	unsigned int iteration;

	for (iteration = 0; double_ptr[iteration] != NULL; iteration++)
		printf("%d: %s\n", iteration, double_ptr[iteration]);

	return (0);
}
