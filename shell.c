#include "main.h"
/**
 * main - entry
 * @argc: argument count
 * @argv: argument vector
 * @env: environment vaiable
 *
 * Return: 0 for success
 */
int main(int argc, char *argv[], char **env)
{
	if (argc > 1)
		argv[1] = NULL;
	prompt(argv, env);
	return (0);
}
