#include "shell.h"

/**
 * main - entrypoint to the whole shell
 * @ac: number of variable inputs
 * @av: the pointer to a pointer holding the variable input
 * @env: the pointer to a pointer holding the environment variables
 * Return: 0 for success
 */
int main(int ac __attribute__((unused)),
		 char **av __attribute__((unused)),
		 char **env)
{
	int exit_status = 0;
	char **history = NULL;
	list_t *head = NULL;

	while (1)
	{
		if (sub_main(env, &exit_status, &history, &head))
			break;
	}
	if (history)
		free_double_pointer(history);
	if (head != NULL)
		free_list(head, env);
	exit(exit_status);
	return (0);
}
