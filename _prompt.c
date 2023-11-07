#include "shell.h"

/**
 * prompt - creates shell prompt and stdin to exec func
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
	size_t num = 0;
	ssize_t num_char;
	char *str = NULL;
	char *str_arr = {NULL, NULL};

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
	}
}
