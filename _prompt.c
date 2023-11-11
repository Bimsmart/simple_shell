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
	char *str = NULL, *tmp;
	char **str_arr;
	int status;
	pid_t child_pid;
	size_t pt;

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
			if (_strcmp("exit", str_arr[0]) == 0)
			{
				break;
			}
			tmp = check_file(str_arr[0]);
			if (tmp != NULL)
				str_arr[0] = tmp;
			pt = check_path(string[0]);		
			child_pid = fork();
			if (child_pid == -1)
			{
				free(str);
				free(str_arr);
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (execve(str_arr[0], str_arr, env) == -1)
					printf("%s: No such file or directory\n", av[0]);
			} else
				wait(&status);
		}
	}
	free(str_arr);
	free(str);
	exit(0);
}
