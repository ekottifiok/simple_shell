#include "shell.h"

user_input_type *parse_multiline(char **env)
{
	char *user_input = NULL, *buffer1, *buffer2, *parsed_str, *delim;
	size_t max_len = BUFSIZ, iter1 = 0;
	int *control_values;
	user_input_type *list = NULL;

	prompt(env);
	if (getline(&user_input, &max_len, stdin) <= 0)
		return (NULL);
	user_input[strlen(user_input) - 1] = '\0';
	control_values = find_control(user_input);
	if (*control_values)
	{
		if (*control_values == 1)
			delim = "&&";
		else if (*control_values == -1)
			delim = "||";
		parsed_str = strtok(user_input, delim);
		while (parsed_str)
		{
			add_input_string(&list, control_values[iter1++], parsed_str);
			parsed_str = strtok(NULL, delim);
		}
		free(user_input);
	}
	else
	{
		list = add_input_string(&list, 0, user_input);
		free(user_input);
	}
	free(control_values);
	return (list);
}