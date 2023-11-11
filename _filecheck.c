#include "main.h"
#include <dirent.h>

/**
 * check_file - Function to check if system cmd exist. if so avoid fork calling
 * @str: string to apply the check
 * Return : concatenated path string or null if false
 */
char *check_file(char *str)
{
	char *tmp, *str_cats;
	DIR *dir = opendir("/bin/");
	struct dirent *ent;

	if (dir == NULL)
		return (NULL);
	ent = readdir(dir);
	while (ent !=  NULL)
	{
		tmp = entity->d_name;
		if (_strcmp(tmp, str) == 0)
		{
			str_cats = strcat("/bin/", str);
			closedir(dir);
			return (str_cats);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
