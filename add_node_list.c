#include "main.h"

/**
 * add_node_list - adds a new node to the list
 *
 * @head: the list of the head
 * @string: the string to be added to the list
 * Return: list_type
 */
list_type *add_node_list(list_type **head, char *string)
{
	list_type *newNode, *buffer;

	newNode = malloc(sizeof(list_type));
	if (!newNode)
		return (NULL);
	newNode->string = _strdup(string);
	newNode->next = NULL;
	buffer = *head;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (buffer->next)
		{
			buffer = buffer->next;
		}
		buffer->next = newNode;
	}
	
	return (*head);
}
