#include "main.h"

/**
 * prompt - creates shell prompt and stdin to exec func
 * @av: argument vector
 * @env: environment variable
 */
void prompt(char **av, char **env)
{
	size_t num = 0, imbt, pt;
	ssize_t num_char;
	char *str = NULL, *error_message, *tmp, **str_arr;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		num_char = getline(&str, &num, stdin);
		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (*str != '\n')
		{
			str_arr = _str_tok(str);
			imbt = match_builtin(str_arr);
			error_message = _strcat(str_arr[0], ": command not found\n");
			tmp = check_file(str_arr[0]);
			if (tmp != NULL)
				str_arr[0] = tmp;
			else
				pt = check_path(str_arr[0]);
			if (pt == 1 || tmp)
			{
				exec_commands(av, str_arr, env);
				if (isatty(STDIN_FILENO) == 0)
					exit(EXIT_SUCCESS);
			}
			if (imbt == 0 && pt != 1 && tmp == NULL)
				write(STDERR_FILENO, error_message, _strlen(error_message));
		}
	}
	exit(EXIT_SUCCESS);
}
