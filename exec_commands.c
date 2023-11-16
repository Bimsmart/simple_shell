#include "main.h"
/**
 * exec_commands - this function forks and executes
 * @str_arr: arguments
 * @av: argument vector
 * @env: environmental variable
 * Return: void
 */
void exec_commands(char **av, char **str_arr, char *env[])
{
	int status;
	pid_t child_pid;
	char *erro_message;

	erro_message = strcat(av[0], ": No such file or directory\n");
	child_pid = fork();
	if (child_pid < 0)
	{
		return;
	}
	if (child_pid == 0)
	{
		if (execve(str_arr[0], str_arr, env) == -1)
			write(STDERR_FILENO, erro_message, strlen(erro_message));
	}
	else
		wait(&status);
}
