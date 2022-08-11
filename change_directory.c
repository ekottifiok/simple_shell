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

	if (strcmp(path, "/") && *path != '/')
	{
		buffer = strdup(old_path);
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
 * Return: 0 success and -1 failure
 */
int change_directory(char **env, char *string, list_t **head)
{
	char *path = NULL, *old_path, *delimiter = " ";
	int flag_path = 0;

	path = strtok(string, delimiter);
	path = strtok(NULL, delimiter);
	old_path = get_env_variable(env, "PWD");
	if (!path)
	{
		path = get_env_variable(env, "HOME");
		flag_path = 1;
	}
	else if (!strcmp(path, "-"))
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
		else
		{
			puts(path);
		}
	}
	if (chdir(path))
	{
		printf("bash: cd: %s: No such file or directory\n", path);
		return (1);
	}
	set_env_variable(env, "OLDPWD", old_path, head);

		sub_change_directory(old_path, path, env, head);

	if (flag_path)
		free(path);
	free(old_path);
	return (0);
}
