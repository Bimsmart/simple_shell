#include "main.h"

/**
 * _strcmp - this function compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if same or 1 or -1 otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/**
 * _strcat - concatenates string
 * @dest: dest parameter
 * @src: source parameter
 * Return: The concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int a, b, c, i = 0, j = 0;
	char *new;

	a = _strlen(dest);
	b = _strlen(src);
	c = a + b + 1; /* +1 to include terminating null byte*/
	new = malloc(sizeof(char) * c);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
		new[i] = dest[i];
	while (j < b)
		new[i] = src[j], i++, j++;
	new[i] = '\0';
	return (new);
}
/**
 * _strlen - computes the length of a string
 * excluding terminating null byte
 * @s: pointer to string
 * Return: returns the length of a string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _atoi - converts a string to an integer
 * @s: pointer to string
 * Return: 0 if no number in the string
 * otherwise return the number
 */
int _atoi(char *s)
{
	int index = 0;
	unsigned int number = 0;
	int mult = 1;
	int check = 0;

	while (s[index])
	{
		if (s[index] == '-')
			mult *= -1;
		while (s[index] >= '0' && s[index] <= '9')
		{
			check = 1;
			number = (number * 10) + (s[index] - '0');
			index++;
		}
		if (check == 1)
			break;
		index++;
	}
	number *= mult;
	return (number);
}
/**
 * _strcpy - copies a string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
