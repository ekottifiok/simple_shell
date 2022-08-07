//
// Created by ifiokekott on 8/7/22.
//
#include "shell.h"

/**
 * free_list - frees the content of the list
 *
 * @head: the pointer of the head
 */
void free_list(list_t *head, char **env)
{
	list_t *buffer;

	while (head)
	{
		buffer = head->next;
		free(env[head->value]);
		free(head);
		head = buffer;
	}
}