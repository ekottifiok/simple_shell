#include "main.h"

/**
 * print_list - prints the content list
 *
 * @h: the list
 * Return: size_t iteration the number of element in the list
 */
size_t print_list(list_type *h)
{
	size_t iteration = 0;

	while (h)
	{
		if (!h->string)
			printf("[0] (nil)");
		else
			printf("[%ld] %s", iteration, h->string);
		h = h->next;
		iteration++;
	}
	return (iteration);
}
