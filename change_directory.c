//
// Created by ifiokekott on 8/5/22.
//
#include "shell.h"

int change_directory(char *path)
{
	if (chdir(path))
		printf("bash: cd: %s: No such file or directory\n", path);
	return (0);
}