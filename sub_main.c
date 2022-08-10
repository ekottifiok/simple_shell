#include "shell.h"

int sub_main(char **env, int *exit_status, char ***history, list_t **head)
{
	user_input_type *input, *input_buffer;
	char *buffer, *buffer2, *delimiter = " ";
	unsigned int iter2, iteration;
	int exit_continue;
	input = parse_multiline(env);
	input_buffer = input;
	for (iter2 = 0, exit_continue = 0; input; iter2++, input = input->next)
	{
		buffer = input->string;
		while (*buffer == ' ')
			*buffer++;
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
				printf("Command '%s' not found\n", buffer);
			if (input->add_or == -1)
				break;
			add_input_history(&history, buffer);
		}
	}
	free_user_input_type(input_buffer);
	return (exit_continue);
}
