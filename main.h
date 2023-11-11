#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#define MAX_COMMANDS 10

void prompt(char **av, char **env);
char **_str_tok(char *str);
int _strcmp(const char *s1, const char *s2);
char *check_file(char *str)
void prompt(char **av, char **env)
endif
