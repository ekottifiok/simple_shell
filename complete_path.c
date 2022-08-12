#include "shell.h"

/**
 * freed - handles the freeing
 * @str1: string to be freed
 * @str2: string to be freed
 * @str3: string to be freed
 */
void freed(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
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
	*buffer1, *buffer2 = strdup(string),
	*complete_string, *incomplete_path, *delimiter = " ", *path_delimiter = ":";
	struct stat st;

	incomplete_path = strtok(buffer2, delimiter);
	path = get_env_variable(environment, "PATH");
	path_token = strtok(path, path_delimiter);
	buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	complete_string = malloc(sizeof(char));
	if (!complete_string)
		return (NULL);
	while (path_token != NULL)
	{
		buffer = realloc(buffer,
						 _strlen(path_token) + _strlen(incomplete_path) + 2);
		if (buffer == NULL)
			return (NULL);
		_strcpy(buffer, path_token);
		strcat(buffer, "/");
		strcat(buffer, incomplete_path);
		if (stat(buffer, &st) == 0)
		{
			complete_string = realloc(complete_string,
									  _strlen(string) + _strlen(buffer) + 2);
			_strcpy(complete_string, buffer);
			buffer1 = copy_string_index(string, 0, delimiter);
			if (buffer1)
			{
				strcat(complete_string, buffer1);
				free(buffer1);
			}
			break;
		}
		path_token = strtok(NULL, path_delimiter);
	}
	freed(buffer, path, buffer2);
	return (complete_string);
}
