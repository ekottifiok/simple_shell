#include "shell.h"

/**
 * freed - handles the freeing
 * @str2: string to be freed
 * @str3: string to be freed
 */
void freed(char *str2, char *str3)
{
	free(str2);
	free(str3);
}

/**
 * check_file - checks if a path exist
 * @path: path to be checked
 * @user_input: user inputted string
 * Return: returns the path if it exit and null if not
 */
char *check_file(char *path, char *user_input)
{
	char *delimiter = " ", *buffer, *complete_string;
	struct stat st;

	if (stat(path, &st) == 0)
	{
		complete_string = path;
		buffer = copy_string_index(user_input, 0, delimiter);
		if (buffer)
		{
			strcat(complete_string, buffer);
			free(buffer);
		}
		return (complete_string);
	}
	return (NULL);
}

/**
 * complete_path - complete a path based on input
 * @string: the string to be completed
 * @environment: global environment variable
 * Return: the completed string
 */
char *complete_path(char *string, char **environment)
{
	char *path, *path_token, *buffer,
	*buffer2 = _strdup(string),
	*complete_string = NULL, *incomplete_path,
	*delimiter = " ", *path_delimiter = ":";


	incomplete_path = strtok(buffer2, delimiter);
	path = get_env_variable(environment, "PATH");
	path_token = strtok(path, path_delimiter);
	buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	while (path_token != NULL)
	{
		buffer = realloc(buffer, (_strlen(path_token) + _strlen(incomplete_path)
		+ _strlen(string) + 2) * sizeof(char));
		if (!buffer)
			return (NULL);
		_strcpy(buffer, path_token);
		_strcat(buffer, "/");
		_strcat(buffer, incomplete_path);
		complete_string = check_file(buffer, string);
		if (complete_string)
			break;
		path_token = strtok(NULL, path_delimiter);
	}
	freed(path, buffer2);
	if (complete_string && complete_string[0] != '\0')
		return (complete_string);
	if (!complete_string)
		free(buffer);
	else
		free(complete_string);
	return (NULL);
}
