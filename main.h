#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#define MAX_COMMAND 10

void prompt(char **av, char **env);
char **_str_tok(char *str);

#endif
