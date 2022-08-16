#include "shell.h"

/**
 * exit_command - converts the string that carries the exit command
 * @string: the string that carries the exit status
 * Return: returns the value of the exit status
 */
int exit_command(char **env, char *string)
{
	unsigned int iteration1, iteration2;
	char *str_buf2, *delimiter = " ", *intro;
	int  result = 0;

	str_buf2 = strtok(string, delimiter);
	str_buf2 = strtok(NULL, delimiter);

	if (str_buf2)
	{
		iteration1 = _strlen(str_buf2);
		if (iteration1 == 0)
			return (0);
		if (*str_buf2 == '-')
		{
			iteration2 = 1;
			iteration1--;
		}
		else
			iteration2 = 0;
		for (; iteration1 > 0; iteration2++)
		{
			if (!(str_buf2[iteration2] >= '0' && str_buf2[iteration2] <= '9'))
				return (0);
			result += STR_TO_INT(str_buf2[iteration2])
					* _pow_recursion(10, --iteration1);
		}
		if (*str_buf2 == '-')
			result *= -1;
	}
	if (result < 0)
	{
		intro = get_env_variable(env, "_");
		fprintf(stderr, "%s: 1: exit: Illegal number: %d\n", intro, result);
		result = 2;
		free(intro);
	}
	return (result);
}
