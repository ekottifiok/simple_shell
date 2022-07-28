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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

/* custom data type */
typedef struct history_list
{
	char *command;
	struct history_list *next;
} history_type;

/* our libraries */
history_type *history (history_type **, char *);
size_t print_history(history_type *h);
void free_history(history_type *head);

/* dependecy library */
void *_realloc(void *, unsigned int, unsigned int);
char *_strcpy(char *, char *);
size_t _strlen(char *);
size_t _strcmp(char *, char *);
char *_strdup(char *str);

#endif