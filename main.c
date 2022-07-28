#include "main.h"

/**
 * main - entrypoint to function that is a simple shell
 * Return: int 0 success
 *
 */
int main(void)
{
	char *input_characters;
	history_type *history_list = NULL;
	size_t input_len, max_len = BUFSIZ;

	input_characters = malloc(sizeof(char *) * BUFSIZ);
	while (1)
	{
		printf("($) ");
		input_len = getline(&input_characters, &max_len, stdin);
		if (input_len > 0)
		{
			history_list = history(&history_list, input_characters);
			if (_strcmp(input_characters, "exit") == 4)
				break;
		}
	}
	printf("Bye till next time\n");
	free_history(history_list);
	free(input_characters);
	return (0);
}
