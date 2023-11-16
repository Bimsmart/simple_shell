#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#define MAX_COMMANDS 20

/**
 * struct builtin_s - struct for built-in commands
 * @command: built-in command to be executed
 * @fptr: function pointer to execute built-in command
 */
typedef struct builtin_s
{
	char *command;
	size_t (*fptr)(char **);
} builtin_t;

char **_str_tok(char *str);
int _strcmp(const char *s1, const char *s2);
char *check_file(char *str);
void prompt(char **av, char **env);
void exec_commands(char **av, char **str_arr, char *env[]);
int check_path(char *str);
size_t _setenv(char **str);
size_t my_exit(char **str);
size_t match_builtin(char **str);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif
