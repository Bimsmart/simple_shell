#include "main.h"

/**
 * check_path - check if string has"/bin
 * @str: the string to check
 * Return: 0 if false or 1 if true
 */
int check_path(char *str)
{
	char *bin_str = "/bin/", *pt, *tmp;
	int i = 0, j = 0;

	pt = malloc(sizeof(char *) * 50);
	if (pt == NULL)
	{
		return (0);
	}
	while (bin_str[i] != '\0')
	{
		if (bin_str[i] != str[i])
		{
			free(pt);
			return (0);
		}
		i++;
	}
	while (str[i] != '\0')
	{
		pt[j] = str[i];
		i++;
		j++;
	}
	pt[j] = '\0';
	tmp = check_file(pt);
	if (tmp != NULL)
	{
		free(pt);
		return (1);
	}
	return (0);
}
