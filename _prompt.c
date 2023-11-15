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
	char *str = NULL, *tmp, **str_arr;
	int i = 0;

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
				break;
			tmp = check_file(str_arr[0]);
			if (tmp != NULL)
				str_arr[0] = tmp;
			else
				pt = check_path(str_arr[0]);
			if (pt == 1 || tmp)
			{
				exec_commands(av, str_arr, env);
			}
			if (pt == 0 && tmp == NULL)
				printf("./shell: No such file or directory\n");
		}
	}
	free(tmp);
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	free(str);
	exit(0);
}
