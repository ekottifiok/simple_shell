#include "shell.h"

/**
 * control_converter - finds the right control with a specifier as input
 * @specifier: integer specifier
 * Return: returns the specifier
 */
char *control_converter(int specifier)
{
	if (specifier == 1)
		return ("&&");
	else if (specifier == -1)
		return ("||");
	else if (specifier == 2)
		return (";");
	return (NULL);
}

/**
 * parse_multiline - parses the multiline
 * @user_input: the input by the user
 *
 * Return: the user_input_type
 * a custom data type carrying the input and control
 */
user_input_type *parse_multiline(char *user_input)
{
	char *parsed_str, *delim;
	size_t iter1 = 0;
	int *control_values;
	user_input_type *list = NULL;

	user_input[_strlen(user_input) - 1] = '\0';
	control_values = find_control(user_input);
	if (*control_values)
	{
		delim = control_converter(*control_values);
		parsed_str = strtok(user_input, delim);
		while (parsed_str)
		{
			add_input_string(&list, control_values[iter1++], parsed_str);
			parsed_str = strtok(NULL, delim);
		}
	}
	else
	{
		list = add_input_string(&list, 0, user_input);
	}
	free(control_values);
	return (list);
}
