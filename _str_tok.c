#include "main.h"
#include <string.h>
/**
 * _str_tok- this function tokenizes a string
 * @str: the string to be splited
 * Return: a pointer to an array of strings
 */
char **_str_tok(char *str)
{
	int i = 0, j = 0;
	char *argv[] = {NULL, NULL};

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
	argv[j] = strtok(str, " ");
	while (argv[j] != NULL)
		argv[++j] == strtok(NULL, " ");
	return (argv);
}
