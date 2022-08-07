//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

char *complete_path(char *string, char **environment)
{
	char *path, *path_token, *buffer, *buffer2, *buffer3, *buffer4, *complete_string, *incomplete_path, *delimiter = " ", *path_delimiter = ":";
	struct stat st;

	buffer2 = strdup(string);
	incomplete_path = strtok(buffer2, delimiter);
	//    gets the environment variable for PATH
	path = get_env_variable(environment, "PATH");
	buffer3 = strdup(path);
	path_token = strtok(buffer3, path_delimiter);
	// // Keep printing tokens while one of the delimiters present in path[].
	buffer = malloc(sizeof(char));
	if (buffer == NULL)
		return (NULL);
	complete_string = malloc(sizeof(char));
	if (complete_string == NULL)
		return (NULL);
	while (path_token != NULL)
	{
		buffer = realloc(buffer, strlen(path_token) + strlen(incomplete_path) + 2);
		if (buffer == NULL)
			return (NULL);
		strcpy(buffer, path_token);
		strcat(buffer, "/");
		strcat(buffer, incomplete_path);
		if (stat(buffer, &st) == 0)
		{
			complete_string = realloc(complete_string, strlen(string) + strlen(buffer) + 2);
			while (*string)
			{
				if (*string == *delimiter)
					break;
				*string++;
			}
			strcpy(complete_string, buffer);
			strcat(complete_string, string);
			break;
		}
		path_token = strtok(NULL, path_delimiter);
	}
	free(buffer);
	free(path);
	free(buffer2);
	free(buffer3);
	return (complete_string);
}
