#include "main.h"

/**
 * prompt - creates shell prompt and stdin to exec func
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
	size_t num = 0, pt;
	ssize_t num_char;
	char *str = NULL, *tmp;
	char **str_arr;

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
			printf("quarter check");
			tmp = check_file(str_arr[0]);
			printf("half check");
			if (tmp != NULL)
				str_arr[0] = tmp;
			else
				pt = check_path(str_arr[0]);
			printf("first check");
			if (pt == 1 || tmp)
			{
				printf("second check");
				exec_commands(av, str_arr, env);
			}
			printf("third check");
			if (pt == 0 && tmp == NULL)
				printf("./shell: No such file or directory\n");
		}
	}
	free(str_arr);
	free(str);
	exit(0);
}
