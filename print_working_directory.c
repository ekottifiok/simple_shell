//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

int print_working_directory(char **env, char *path __attribute__((unused)), list_t **head __attribute__((unused)))
{
	char *buffer;
	buffer = get_env_variable(env, "PWD");
	puts(buffer);
	free(buffer);
	// puts("Concept works");
	return (0);
}
