//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

char *complete_path(char *string, char **environment)
{
    char *path, *path_token, *buffer, *complete_string, *incomplete_path, *delimiter = " ", *path_delimiter = ":";
    struct  stat st;

    incomplete_path = strtok(strdup(string), delimiter);
//    gets the environment variable for PATH
    path = get_env_variable(environment, "PATH");
    path_token = strtok(strdup(path), path_delimiter);
    // Keep printing tokens while one of the delimiters present in path[].
    buffer = malloc(sizeof(char));
    if (buffer == NULL)
        return (NULL);
    complete_string = malloc(sizeof(char ));
    if (complete_string == NULL)
        return (NULL);
    while (path_token != NULL)
    {
        buffer = realloc(buffer, strlen(path_token)+ strlen(incomplete_path) + 2);
        if (buffer == NULL)
            return (NULL);
        buffer = strcpy(strcat(strdup(path_token), "/"), incomplete_path);
        if (stat(buffer, &st) == 0)
        {
            complete_string = realloc(complete_string, strlen(string)+ strlen(buffer));
            while (*string)
            {
                if (*string == *delimiter)
                    break;
                *string++;
            }
            strcpy(complete_string, buffer);
            strcat(complete_string, string);
            free(buffer);
            return (complete_string);
        }
        path_token = strtok(NULL, path_delimiter);
    }
}