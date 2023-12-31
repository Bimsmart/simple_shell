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
	char **av, *s;

	av = malloc(MAX_COMMANDS * sizeof(char *));
	if (av == NULL)
	{
		free(av);
		exit(1);
	}
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	s = strtok(str, " ");
	while (s != NULL)
	{
		av[j] = s;
		j++;
		s = strtok(NULL, " ");
	}
	av[j] = NULL;
	return (av);
}
