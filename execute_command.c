#include "shell.h"
#include <errno.h>
/**
 * execute_command - executes a command
 * @full_path: the command to be executed
 * @argv: list of arguments
 * @command: The orginal command the user entered
 * @cpy_c: Is the copy of the command to free if error happens
 * Return: Execuation result
 */
int execute_command(char *full_path, char **argv, char *command, char *cpy_c)
{
	pid_t pid;
	int exec_status;
	extern char **environ;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			if (errno == EACCES)
			{
				perror("permission deniend\n");
				exit(126);
			}
			else
			{
				perror("not found\n");
				free_args(argv), free(full_path), free(command), free(cpy_c);
				exit(127);
			}
			exit(1);
		}
	}
	else
	{
		wait(&exec_status);
		exec_status = WEXITSTATUS(exec_status);
	}
	return (exec_status);
}

