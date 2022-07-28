#include "main.h"

/**
 * print_history - prints the content list
 *
 * @h: the list
 * Return: size_t iteration the number of element in the list
 */
size_t print_history(history_type *h)
{
	size_t iteration = 0;

	while (h)
	{
		if (!h->command)
			printf("[0] (nil)");
		else
			printf("[%ld] %s", iteration, h->command);
		h = h->next;
		iteration++;
	}
	return (iteration);
}
