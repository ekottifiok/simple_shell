#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc
 * and free
 * @ptr: The pointer
 * @old_size: The old memory size
 * @new_size: The new memory size
 *
 * Return: void pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (new_size == old_size)
		return (ptr);

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);

	if (ptr != NULL && (new_size > old_size))
		_strcpy(new_ptr, ptr);

	free(ptr);
	return (new_ptr);
}
