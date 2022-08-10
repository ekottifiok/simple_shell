#include "shell.h"

/**
 * free_double_pointer - frees a double pointer
 * @db_ptr: the double pointer to be freed
 * Return: 0 as success
 */
int free_double_pointer(char **db_ptr)
{
	unsigned int size;
	size_t iteration;

	for (size = 0; db_ptr[size]; size++)
		;

	for (iteration = 0; iteration < size; iteration++)
		free(db_ptr[iteration]);

	free(db_ptr);
	return (0);
}
