#include "shell.h"

/**
 * sub_main - an extension of the shell
 * @env: global environment variable
 * @exit_status: the status to be exited
 * @history: history list
 * @head: the changes to the environment variable
 * Return: either 0 to continue or 1 to break
 */
int sub_main(char **env, int *exit_status, char ***history, list_t **head)
{
	user_input_type *input, *input_buffer;
	char *buffer;
	unsigned int iter2;
	int exit_continue;

	input = parse_multiline(env);
	input_buffer = input;
	for (iter2 = 0, exit_continue = 0; input; iter2++, input = input->next)
	{
		buffer = input->string;
		while (*buffer == ' ')
			(*buffer)++;
		if (!strncmp(buffer, "exit", 4) || *buffer == '\0')
		{
			exit_continue = 1;
			*exit_status = exit_command(buffer);
		}
		else if (!strcmp(buffer, "history") && history)
		{
			print_double_pointer(*history);
		}
		else
		{
			if (execute_decision(buffer, env, &head))
			{
				printf("Command '%s' not found\n", buffer);
				if (input->add_or == 1)
					break;
				if (input->add_or == 2)
					continue;
			}
			if (input->add_or == -1)
				break;
			add_input_history(&history, buffer);
		}
		if (*input->string == ' ')
			free(buffer);
	}
	free_user_input_type(input_buffer);
	return (exit_continue);
}
