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
	char *user_input = NULL, *buffer, *buffer2, **history = NULL, *delimiter = " ";
	size_t max_len = BUFSIZ, iteration = 0;
	unsigned int exit_status = 0;
	list_t *head;

	head = NULL;
	history = malloc(sizeof(char *) * 2);
	history[0] = NULL;
	while (1)
	{
		prompt(env);
		getline(&user_input, &max_len, stdin);
		// removes the new line at the end of the string
		user_input[strlen(user_input) - 1] = '\0';
		if (!strcmp(user_input, "exit") || *user_input == '\0')
			break;
		if (!strcmp(user_input, "history"))
		{
			print_double_pointer(history);
			continue;
		}
		else if (!strncmp(user_input, "exit ", 5))
		{
			buffer = strdup(user_input);
			buffer2 = strtok(buffer, delimiter);
			buffer2 = strtok(NULL, delimiter);

			if (*buffer2)
				exit_status = exit_command(buffer2);
			free(buffer);
			break;
		}
		if (iteration > 0)
			history = realloc(history, sizeof(char *) * (iteration+2));
		history[iteration] = malloc(sizeof(char) * (1+strlen(user_input)));
		strcpy(history[iteration], user_input);
		history[iteration+1] = NULL;
		iteration++;
		if (execute_decision(user_input, env, &head))
			printf("Command '%s' not found\n", user_input);
	}
	if (head != NULL)
		free_list(head, env);
	if (*history != NULL)
		free_double_pointer(history);
	else
		free(history);
	free(user_input);
	if (exit_status > 0)
		exit(exit_status);
	return (0);
}
