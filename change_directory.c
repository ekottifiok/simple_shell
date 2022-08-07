/*
 * Created by ifiokekott on 8/5/22.
 */
#include "shell.h"

int change_directory(char **env, char *string, list_t **head)
{
	char *buffer, *path = NULL, *new_path, *old_path, *delimiter = " ";
	int flag_path = 0;
	/*
	 * removes the cd from the string
	 */
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
		puts(path);
		flag_path = 1;
		if (!path)
		{
			free(old_path);
			free(path);
			puts("bash: cd: OLDPWD not set");
			return (0);
		}
	}

	if (chdir(path))
	{
		printf("bash: cd: %s: No such file or directory\n", path);
		return (0);
	}
	set_env_variable(env, "OLDPWD", old_path, head);
	if (strcmp(path, "/") && *path != '/')
	{
		buffer = strdup(old_path);
		buffer = realloc(buffer, (strlen(buffer) + strlen(path) + 2));
		if (*path != '/' && buffer[strlen(buffer) - 1] != '/')
			strcat(buffer, "/");
		strcat(buffer, path);
		set_env_variable(env, "PWD", buffer, head);
		free(buffer);
	}
	else
	{
		set_env_variable(env, "PWD", path, head);
	}
	if (flag_path)
		free(path);
	free(old_path);
	return (0);
}