/**
 * @file main.h
 * @authors Ifiok Ekott (ekottifiok@gmail.com), Kamal Muhammad (meetkamal256@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SHELL_H
#define SHELL_H

/* libraries from gcc */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* custom definitions */
#define MAX_SIZE_ARG 16
#define MAX_SIZE_CMD 256


/* custom data type */
typedef struct
{
	char *keyword;
	int (*op)(char *);
} execute_functions;

/* custom standard library */
void *_realloc(void *, unsigned int , unsigned int );

/* new functions */
int prompt(char **);
int execute_command(char *[], char **);
int execute_decision(char *, char **);
char **parse_string(char *, char *);
void free_double_pointer(char **, size_t );
char *get_env_variable(char **, char *);
char *complete_path(char *, char **);
int (*get_builtin_function(char *))(char *);
int change_directory(char *);

#endif