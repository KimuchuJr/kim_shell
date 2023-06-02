#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

#define DELIMITER " \t\r\n"
#define BUFF_SIZE 1024
#define MAX_INPUT_LENGTH 1024
#define MAX_COMMAND_LENGTH 100

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

void loop(void);
char *get_input(void);
char **split_tokens(char *input);
int execute_commands(char **args, int line_number, char *prog_name);
void kpsh_exit(char **args);
int get_num_args(char **args);
void change_directory(char **args);
void set_env(char **args);
void unset_env(char **args);
char *handle_path(char **args);

/* custom functions */

char *my_strchr(const char *str, int ch);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
int my_putchar(int c);
void my_printf(char *format, ...);

/* more custom functions */

char *my_getenv(const char *name);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_memcpy(char *dest, char *src, unsigned int n);
void *my_realloc(void *ptr, unsigned int new_size);
char *my_strcat(char *dest, const char *src);
int my_strcmp(char *fs1, char *ss2);
char *my_strncpy(char *desti, const char *src, int b);
int my_strlen(const char *s);
char *my_strcpy(char *dest, const char *src);
int my_atoi(char *s);

/* new functions, custom functions and prototypes */

int print_prompt(void);
void free_bufs(char **buffer);
void signal_handler(int n);
void cd_error_message(const char *message);
char *handle_special_path(char **args);
const char *my_strstr(const char *haystack, const char *needle);
int my_itoa(char *str, int num);
char *command_error(int line_no, char *p_name, char *cmd);
void print_error_message(int line_no, char *p_name, char *cmd);
char *my_strdup(const char *str);

int check_args(char **args, char *input);

#endif
