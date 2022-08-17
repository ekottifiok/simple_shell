#include "shell.h"

/**
 * main - entrypoint to the whole shell
 * @ac: number of variable inputs
 * @av: the pointer to a pointer holding the variable input
 * @env: the pointer to a pointer holding the environment variables
 * Return: 0 for success
 */
int main(int ac __attribute__((unused)),
		 char **av,
		 char **env)
{
	int exit_status = 0;
	char **history = NULL, *user_input = NULL;
	size_t max_len = BUFSIZ, len_user_input;
	list_t *head = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(env);
		len_user_input = _getline(&user_input, &max_len, stdin);
		user_input[len_user_input - 1] = '\0';

		if (sub_main(env, &exit_status, &history, &head, user_input, av[0]) ||
		!isatty(STDIN_FILENO))
			break;

	}
	free(user_input);
	if (history)
		free_double_pointer(history);
	if (head != NULL)
		free_list(head, env);

	exit(exit_status);
}
