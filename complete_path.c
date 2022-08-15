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
 * complete_path - complete a path based on input
 * @string: the string to be completed
 * @environment: global environment variable
 * Return: the completed string
 */
char *complete_path(char *string, char **environment)
{
	char *path, *path_token, *buffer,
	*buffer1, *buffer2 = _strdup(string),
	*complete_string = NULL, *incomplete_path,
	*delimiter = " ", *path_delimiter = ":";
	struct stat st;

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
		if (stat(buffer, &st) == 0)
		{
			complete_string = buffer;
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
	freed(path, buffer2);
	if (complete_string[0] != '\0')
		return (complete_string);
	free(complete_string);
	return (NULL);
}
