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
#ifndef MAIN_H
#define MAIN_H

/* libraries from gcc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/* custom definitions */
#define MAX_SIZE_ARG 16
#define MAX_SIZE_CMD 256

/* custom data type */
typedef struct history_list
{
	char *string;
	struct history_list *next;
} list_type;

/* our libraries */
list_type *add_node_list(list_type **head, char *string);
size_t print_list(list_type *h);
void free_list(list_type *head);
list_type *input_array(char *string);

/* dependecy library */
void *_realloc(void *, unsigned int, unsigned int);
char *_strcpy(char *, char *);
size_t _strlen(char *);
size_t _strcmp(char *, char *);
char *_strdup(char *str);

#endif