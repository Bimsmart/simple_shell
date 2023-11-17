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
	char *err_mess;

	if (argc > 1)
	{
		err_mess = _strcat("Usage: ", argv[0]);
		write(STDERR_FILENO, err_mess, _strlen(err_mess));
		write(STDERR_FILENO, "\n", 1), exit(EXIT_FAILURE);
	}
	prompt(argv, env);
	return (0);
}
