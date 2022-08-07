//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

int echo(char **env __attribute__((unused)), char *string, list_t **head __attribute__((unused)))
{
	while (*string != ' ')
		*string++;
	*string++;
	fprintf(stdout, "%s\n", string);
	return (0);
}