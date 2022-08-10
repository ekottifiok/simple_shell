#include "shell.h"

/**
 * free_user_input_type - frees the user input type
 * @head: the user input type
 */
void free_user_input_type(user_input_type *head)
{
	user_input_type *buffer;

	while (head)
	{
		buffer = head->next;
		free(head->string);
		free(head);
		head = buffer;
	}
}
