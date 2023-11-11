#include "main.h"
/**
 * fork_exec : this function forks and executes
 * @av: argument vector
 * @env: environmental variable
 * Return: void
 */
void fork_exec(char **av, char *env[])
{
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
	}
	else
		wait(&status);
}
