#include "main.h"
#include <dirent.h>

/**
 * check_file - Function to check if system cmd exist. if so avoid fork calling
 * @str: string to apply the check
 * Return: concatenated path string or null if false
 */
char *check_file(char *str)
{
	char *tmp, *str_cats;
	DIR *dir = opendir("/bin/");
	struct dirent *ent;

	str_cats = malloc(sizeof(char) * (_strlen(str) + _strlen("/bin/")));
	if (dir == NULL)
		return (NULL);
	ent = readdir(dir);
	while (ent !=  NULL)
	{
		tmp = ent->d_name;
		if (_strcmp(tmp, str) == 0)
		{
			_strcpy(str_cats, "/bin/");
			str_cats = _strcat(str_cats, str);
			closedir(dir);
			return (str_cats);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	free(str_cats);
	return (NULL);
}
