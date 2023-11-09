#include "main.h"

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
	char **str_arr;
	int status;
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
		num_char = getline(&str, &num, stdin);
		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (*str != '\n')
		{
			str_arr = _str_tok(str);
			child_pid = fork();
			if (child_pid == -1)
			{
				free(str);
				free(str_arr);
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (execve(str_arr[0], av, env) == -1)
					printf("%s: No such file or directory\n", av[0]);
			} else
				wait(&status);
		}
	}
	free(str_arr);
	free(str);
	exit(0);
}
