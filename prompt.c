//
// Created by ifiokekott on 8/4/22.
//
#include "shell.h"

int prompt(char **environment)
{
	char *buffer = get_env_variable(environment, "PWD");
	printf("%s $ ", buffer);
	free(buffer);
	return (0);
}