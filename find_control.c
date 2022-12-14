#include "shell.h"

/**
 * find_control - find which control is in the text
 * @user_input: the users input
 * Return: the control in malloc
 */
int *find_control(char *user_input)
{
	unsigned int iter1, iter2;
	char test[3];
	int *control;

	control = malloc(sizeof(int));
	for (iter1 = 0, iter2 = 0; user_input[iter1]; iter1++)
	{
		test[0] = user_input[iter1];
		test[1] = user_input[iter1 + 1];
		test[2] = '\0';
		if (!_strcmp(test, "&&") || !_strcmp(test, "||")
		|| *test == ';' || *test == '\n')
		{
			control = realloc(control, sizeof(int) * (iter2 + 2));
			if (!_strcmp(test, "&&"))
				control[iter2++] = 1;
			else if (!_strcmp(test, "||"))
				control[iter2++] = 2;
			else if (*test == ';')
				control[iter2++] = 3;
			else if (*test == '\n')
				control[iter2++] = 4;
			control[iter2] = 0;
		}
	}
	if (iter2 == 0)
		*control = 0;
	return (control);
}
