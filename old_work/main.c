#include "main.h"

void prompt(void)
{
	write(1, "($) ", 4);
}

/**
 * main - entrypoint to function that is a simple shell
 * Return: int 0 success
 *
 */
int main(void)
{
	char *command;
	char *arguments[MAX_SIZE_ARG];
	list_type *history_list = NULL;
	size_t max_len = BUFSIZ;

	command = malloc(sizeof(char) * MAX_SIZE_CMD);
	while (1)
	{
		prompt();
		if (getline(&command, &max_len, stdin) > 0 && *command != '\n')
		{
			if (*command == '\0' || _strcmp(command, "exit") == 4)
				break;

			/* removes the trailing newline */
			command[_strlen(command) - 1] = '\0';

			if (_strcmp(command, "history") == 7)
				print_list(history_list);
			add_node_list(&history_list, command);
			convert_to_argv(command, arguments);
			run_command(arguments);
		}
	}
	printf("Bye till next time\n");
	free_list(history_list);
	free(command);
	return (0);
}
