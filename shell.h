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
#define STR_TO_INT(val) (val - 48)
#define INT_TO_STR(val) (val + 48)

/* custom data type */
typedef struct list
{
	char *string;
	int add_or;
	struct list *next;
} user_input_type;
typedef struct list_s
{
	int value;
	struct list_s *next;
} list_t;

typedef struct
{
	char *keyword;
	int (*op)(char **, char *, list_t **);
} execute_functions;

/* custom standard library */
void *_realloc(void *, unsigned int , unsigned int );
int _pow_recursion(i nt , int );
char *_strcpy(char *dest, char *src)
/* new functions */
int sub_main(char **, int *, char ***, list_t **);
int add_input_history(char ****, char *);
int prompt(char **);
int execute_command(char *[], char **);
int execute_decision(char *, char **, list_t ***);
char **parse_string(char *, char *);
int free_double_pointer(char **);
char *get_env_variable(char **, char *);
char *complete_path(char *, char **);
int (*get_builtin_function(char *))(char **, char *, list_t **);
int set_env_variable(char **, char *, char *, list_t **);
int change_directory(char **, char *, list_t **);
int print_working_directory(char **, char *, list_t **);
int echo(char **, char *, list_t **);
int help(char **, char *, list_t **);
int print_double_pointer(char **double_ptr);
int exit_command(char *);
char **copy_double_pointer(char **, int );
int print_env(char **, char *, list_t **);
list_t *add_node(list_t **head, int value);
void free_list(list_t *head, char **);
int *find_control(char *user_input);
user_input_type *add_input_string(user_input_type **, int , char *);
user_input_type *parse_multiline(char **);
void free_user_input_type(user_input_type *head);
ssize_t __getline(char **, size_t *, FILE *);

#endif