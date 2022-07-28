#include "main.h"

/**
 * history - adds a new stringing to the history list
 *
 * @head: original history list
 * @string: new stringing to be added
 * Return: char** pointing to the modified history
 */
history_type *history(history_type **head, char *string)
{
	history_type *newNode, *buffer;
	unsigned int stringLen;

	for (stringLen = 0; string[stringLen] != '\0'; stringLen++)
		;

	newNode = malloc(sizeof(history_type));
	if (!newNode)
		return (NULL);
	newNode->command = _strdup(string);
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
	if (_strcmp(string, "history") == 7)
		print_history(*head);

	return (*head);
}
