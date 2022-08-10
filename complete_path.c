#include "shell.h"

/**
 * freed - handles the freeing
 * @str1: string to be freed
 * @str2: string to be freed
 * @str3: string to be freed
 * @str4: string to be freed
 */
void freed(char *str1, char *str2, char *str3, char *str4)
{
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

/**
 * complete_path - complete a path based on input
 * @string: the string to be completed
 * @environment: global environment variable
 * Return: the completed string
 */
char *complete_path(char *string, char **environment)
{
	char *path, *path_token, *buffer, *buffer2 = strdup(string), *buffer3,
	*complete_string, *incomplete_path, *delimiter = " ", *path_delimiter = ":";
	struct stat st;

	incomplete_path = strtok(buffer2, delimiter);
	path = get_env_variable(environment, "PATH");
	buffer3 = strdup(path);
	path_token = strtok(buffer3, path_delimiter);
	buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	complete_string = malloc(sizeof(char));
	if (!complete_string)
		return (NULL);
	while (path_token != NULL)
	{
		buffer = realloc(buffer,
						 strlen(path_token) + strlen(incomplete_path) + 2);
		if (buffer == NULL)
			return (NULL);
		strcpy(buffer, path_token);
		strcat(buffer, "/");
		strcat(buffer, incomplete_path);
		if (stat(buffer, &st) == 0)
		{
			complete_string = realloc(complete_string,
									  strlen(string) + strlen(buffer) + 2);
			for (; *string; *string++)
			{
				if (*string == *delimiter)
					break;
			}
			strcpy(complete_string, buffer);
			strcat(complete_string, string);
			break;
		}
		path_token = strtok(NULL, path_delimiter);
	}
	freed(buffer, path, buffer2, buffer3);
	return (complete_string);
}
