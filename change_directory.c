#include "shell.h"

/**
 * sub_change_directory - takes care of some processes so that
 * betty can pass
 * @old_path: the old path to be added to OLDPWD
 * @path: new path to be added to PWD
 * @env: the global environment variable
 * @head: carries the environment variable that was edited
 */
void sub_change_directory(char *old_path,
						  char *path, char **env, list_t **head)
{
	char *buffer;

	if (_strcmp(path, "/") && *path != '/')
	{
		buffer = _strdup(old_path);
		buffer = realloc(buffer, (_strlen(buffer) + _strlen(path) + 2));
		if (*path != '/' && buffer[_strlen(buffer) - 1] != '/')
			strcat(buffer, "/");
		strcat(buffer, path);
		set_env_variable(env, "PWD", buffer, head);
		free(buffer);
	}
	else
	{
		set_env_variable(env, "PWD", path, head);
	}
}

/**
 * change_directory - handles the change directory
 * @env: the global environment variable
 * @string: string inputted by user
 * @head: carries the environment variable that was edited
 * @file_name: carries the file name
 * Return: 0 success and -1 failure
 */
int change_directory(char **env, char *string, list_t **head, char *file_name)
{
	char *path = NULL, *old_path, *delimiter = " ";
	int flag_path = 0;

	path = strtok(string, delimiter);
	path = strtok(NULL, delimiter);
	old_path = get_env_variable(env, "PWD");
	if (!path)
	{
		path = get_env_variable(env, "HOME");
		if (!path)
			return (1);
		flag_path = 1;
	}
	else if (!_strcmp(path, "-"))
	{
		path = get_env_variable(env, "OLDPWD");
		flag_path = 1;
		if (!path)
		{
			free(old_path);
			free(path);
			puts("bash: cd: OLDPWD not set");
			return (0);
		}
		puts(path);
	}
	if (chdir(path))
	{
		fprintf(stderr, "%s: 1: cd: can't cd to %s\n",
				file_name, path);
		return (1);
	}
	set_env_variable(env, "OLDPWD", old_path, head);
	sub_change_directory(old_path, path, env, head);
	if (flag_path)
		free(path);
	free(old_path);
	return (0);
}
