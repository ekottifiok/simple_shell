//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

char **copy_double_pointer(char **double_pointer, int plus_size)
{
	size_t size, iter;
	char **new_db_ptr;

	for (size = 0; double_pointer[size]; size++)
		;
	size += plus_size;
	new_db_ptr = malloc(sizeof(char *) * (size));
	for (iter = 0; double_pointer[iter]; iter++)
		new_db_ptr[iter] = strdup(double_pointer[iter]);

	new_db_ptr[size] = NULL;
	return (new_db_ptr);
}