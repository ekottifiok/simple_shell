#include "main.h"

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
			buffer = malloc(sizeof(char) * j + 1);
			position = i - j;
			for (k = 0; position < i; k++, position++)
			{
				if (string[position] == ' ')
					position++;
				buffer[k] = string[position];
			}
			buffer[j] = '\0';
			array = add_node_list(&array, buffer);
			j = i;
		}
		if (!string[i])
			break;
	}
	free(buffer);
	return (array);
}
