#include "main.h"

/**
 * free_history - frees the content of the history
 *
 * @head: the pointer of the haed
 */
void free_history(history_type *head)
{
	history_type *buffer;

	while (head)
	{
		buffer = head->next;
		free(head->command);
		free(head);
		head = buffer;
	}
}
