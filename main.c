#include "main.h"

/**
 * main - entrypoint to function that is a simple shell
 * Return: int 0 success
 *
 */
int main(void)
{
	char *input_characters;
	list_type *history_list = NULL, *array_arguments = NULL;
	size_t max_len = BUFSIZ;

	input_characters = (char *)malloc(sizeof(char) * BUFSIZ);
	while (1)
	{
		printf("($) ");
		if (getline(&input_characters, &max_len, stdin) > 0 && *input_characters != '\n')
		{
			array_arguments = input_array(input_characters); /* "hello fortune friend" return "hello" "fortune" "friend" */
			add_node_list(&history_list, input_characters);
			if (_strcmp(input_characters, "history") == 7)
				print_list(history_list);
			else if (_strcmp(array_arguments->string, "./") == 2) /* "./bin/ls -l" return "./bin/ls", "-l" " */
				printf("%s\n", (array_arguments->next)->string);
			else if (_strcmp(input_characters, "exit") == 4)
				break;
		}
	}
	printf("Bye till next time\n");
	free_list(history_list);
	free(input_characters);
	free_list(array_arguments);
	return (0);
}
