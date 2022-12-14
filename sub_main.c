#include "shell.h"

/**
 * sub_main - an extension of the shell
 * @env: global environment variable
 * @exit_status: the status to be exited
 * @history: history list
 * @head: the changes to the environment variable
 * @user_input: the input by the user
 * @file_name: carries the file name
 * Return: either 0 to continue or 1 to break
 */
int sub_main(char **env, int *exit_status,
			 char ***history, list_t **head, char *user_input,
			 char *file_name)
{
	user_input_type *input, *input_buffer;
	char *buffer;
	unsigned int iter2;
	int exit_continue;

	input = parse_multiline(user_input);
	input_buffer = input;
	for (iter2 = 0, exit_continue = 0; input; iter2++, input = input->next)
	{
		buffer = input->string;
		if (!_strncmp(buffer, "exit", 4) || *buffer == '\0' || *buffer == 3)
		{
			exit_continue = 1;
			*exit_status = exit_command(buffer, file_name);
			break;
		}
		else if (!_strcmp(buffer, "history") && history)
		{
			print_double_pointer(*history);
		}
		else
		{
			if (execute_decision(buffer, env, &head, file_name))
			{
				printf("Command '%s' not found\n", buffer);
				if (input->add_or == 1)
					break;
				if (input->add_or == 3 || input->add_or == 4)
					continue;
			}
			if (input->add_or == 2)
				break;
			add_input_history(&history, buffer);
		}
		if (*input->string == ' ')
			free(buffer);
	}
	free_user_input_type(input_buffer);
	return (exit_continue);
}
