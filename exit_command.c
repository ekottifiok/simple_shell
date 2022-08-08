#include "shell.h"

/**
 * exit_command - converts the string that carries the exit command
 * @string: the string that carries the exit status
 * Return: returns the value of the exit status
 */
int exit_command(char *string)
{
	unsigned int iteration1, result, iteration2;

	iteration1 = strlen(string);
	if (iteration1 == 0)
		return (0);
	for (iteration2 = 0, result = 0; iteration1 > 0; iteration2++)
	{
		if (!(string[iteration2] >= '0' && string[iteration2] <= '9'))
			return (-1);
		result += STR_TO_INT(string[iteration2]) * _pow_recursion(10, --iteration1);
	}
	return (result);
}