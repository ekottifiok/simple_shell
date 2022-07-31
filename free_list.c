#include "main.h"

/**
 * free_list - frees the content of the history
 *
 * @head: the pointer of the haed
 */
void free_list(list_type *head)
{
	list_type *buffer;

	while (head)
	{
		buffer = head->next;
		free(head->string);
		free(head);
		head = buffer;
	}
}
