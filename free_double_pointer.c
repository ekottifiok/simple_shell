//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

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