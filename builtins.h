#ifndef BUILT_H
#define BUILT_H

#include <stddef.h>
typedef void (*builtin_func_t)(char **);

/**
 *  * struct builtin - represents a built-in function
 *   * @name: the name of the built-in function
 *    * @func: a pointer to the built-in function
 *     */

typedef struct builtin
{
	char *name;
	builtin_func_t func;
} builtin_t;

void kpsh_exit(char **args);
void change_directory(char **args);
void set_env(char **args);
void unset_env(char **args);
void builtin_echo(char **args);
void print_env(void);

builtin_t builtins[] = {
	{"exit", kpsh_exit},
	{"cd", change_directory},
	{"setenv", set_env},
	{"unsetenv", unset_env},
	{"echo", builtin_echo},
	{"env", (builtin_func_t)print_env},
	{NULL, NULL}
};

#endif /* BUILTINS_H */
