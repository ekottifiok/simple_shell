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
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* custom definitions */
#define STR_TO_INT(val) (val - 48)
#define INT_TO_STR(val) (val + 48)

/* custom data type */
/**
 * struct list - list that carries the broken
 * up commands and their
 * @string: a command sent by the user
 * @add_or: it's either an add or an or
 * @next: address to the next location
 */
typedef struct list
{
	char *string;
	int add_or;
	struct list *next;
} user_input_type;

/**
 * struct list_s - carries the list of
 * values and it next value
 * @value: the int
 * @next: address to the next value
 */
typedef struct list_s
{
	unsigned int value;
	struct list_s *next;
} list_t;

/**
 * struct nameless - nameless struct
 * @keyword: the string that matches the function
 * @op: the function and all it requires
 */
typedef struct nameless
{
	char *keyword;
	int (*op)(char **, char *, list_t **, char *);
} execute_functions;

/* custom standard library */
void *_realloc(void *, unsigned int, unsigned int);
int _pow_recursion(int, int);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int len);
char *_strdup(char *str);
ssize_t _getline(char **, size_t *, FILE *);
int _putchar(int, char);
char *_strcat(char *, char *);
void _puts(char *);
void _printf(char *);

/* new functions */
int sub_main(char **, int *, char ***, list_t **, char *, char *);
char *copy_string_index(char *, unsigned int, char *);
int add_input_history(char ****, char *);
int prompt(char **);
int execute_command(char *[], char **);
int execute_decision(char *, char **, list_t ***, char *);
char **parse_string(char *, char *);
int free_double_pointer(char **);
char *get_env_variable(char **, char *);
char *complete_path(char *, char **);
int set_env_variable(char **, char *, char *, list_t **);
int print_double_pointer(char **double_ptr);
int exit_command(char *, char *);
char **copy_double_pointer(char **, int);
list_t *add_node(list_t **head, unsigned int value);
void free_list(list_t *head, char **);
int *find_control(char *user_input);
user_input_type *add_input_string(user_input_type **, int, char *);
user_input_type *parse_multiline(char *);
void free_user_input_type(user_input_type *head);
ssize_t __getline(char **, size_t *, FILE *);
char *remove_whitespace(char *string);

/*
 * builtin commands
 */
int (*get_builtin_function(char *))(char **, char *, list_t **, char *);
int echo(char **, char *, list_t **, char *);
int help(char **, char *, list_t **, char *);
int change_directory(char **, char *, list_t **, char *);
int print_working_directory(char **, char *, list_t **, char *);
int unset_env(char **, char *, list_t **, char *);
int set_env(char **, char *, list_t **, char *);
int print_env(char **, char *, list_t **, char *);




#endif
