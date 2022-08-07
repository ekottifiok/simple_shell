//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

int print_double_pointer(char **double_ptr)
{
	unsigned int iteration;

	for (iteration = 0; double_ptr[iteration] != NULL; iteration++)
		printf("%d: %s\n", iteration, double_ptr[iteration]);

	return(0);
}
