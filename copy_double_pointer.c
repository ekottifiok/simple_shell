#include "shell.h"

/**
 * copy_double_pointer - copies a double pointer to another pointer
 * @double_pointer: input double pointer
 * @plus_size: size of pointer
 * Return: returns a new double pointer
 */
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
