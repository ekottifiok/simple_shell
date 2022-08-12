#include "shell.h"

/**
 * help - handles the "help" as a builtin command
 * @env: the environment variable
 * @string: the user input string
 * @head: carries the location of the new additions to the env
 * Return: 0 for success
 */
int help(char **env __attribute__((unused)),
		 char *string __attribute__((unused)),
		 list_t **head
		 )
{
	puts("I'm here to help you.");
	puts("How are you doing today?");
	puts("Happy to see you.");
	while (*head)
		break;
	return (0);
}
