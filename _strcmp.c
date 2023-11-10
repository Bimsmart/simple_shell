#include "string.h"
/**
 * _strcmp - this function compares two strings
 * @s1: first string
 * @s2: second string
 * return: 0 if same or 1 or -1 otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]); 
}
