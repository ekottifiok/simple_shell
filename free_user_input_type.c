#include "shell.h"

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