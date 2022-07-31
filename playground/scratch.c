#include "main.h"

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

/**
 * add_node_list - adds a new node to the list
 *
 * @head: the list of the head
 * @string: the string to be added to the list
 * Return: list_type
 */
list_type *add_node_list(list_type **head, char *string)
{
	list_type *newNode = NULL, *buffer;

	newNode = malloc(sizeof(list_type));
	if (!newNode)
		return (NULL);
	newNode->string = malloc(sizeof(char) * strlen(string) + 1);
	strcpy(newNode->string, string);
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

/**
 * input_array - the string is segmented
 *
 * @string: string to be segmented
 * Return: list_type* the segmented list
 */
list_type *input_array(char *string)
{
	size_t i = 0, j = 0, k = 0;
	unsigned int position;
	char *buffer = NULL;
	list_type *array = NULL;

	for (; 1; i++)
	{

		if (string[i] == ' ' || string[i] == '\0')
		{
			j = (i - j);
			buffer = malloc(sizeof(char) * (j + 1));
			position = i - j;
			for (k = 0; position < i; k++, position++)
			{
				if (string[position] == ' ')
					position++;
				buffer[k] = string[position];
			}
			buffer[k] = '\0';
			array = add_node_list(&array, buffer);
			free(buffer);
			j = i;
		}
		if (!string[i])
			break;
	}
	return (array);
}

void main(void)
{
	list_type *array_arg = NULL;
	array_arg = input_array("hello rocsdsc vdffss");
	free_list(array_arg);
}