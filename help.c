//
// Created by ifiokekott on 8/6/22.
//
#include "shell.h"

int help(char **env __attribute__((unused)), char *string __attribute__((unused)), list_t **head __attribute__((unused)))
{
	puts("I'm here to help you.");
	puts("How are you doing today?");
	puts("Happy to see you.");
	return (0);
}
