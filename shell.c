#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * _prompt - displays prompt
 */
void _prompt(void)
{
	write(STDOUT_FILENO, "mainajay$", 9);
}

/**
 * _error - handles errors
 * @name: program name
 * @message: error message
 */
void _error(char *name, char *message)
{
	fprintf(stderr, "%s: %s\n", name, message);
}

/**
 * _command - executes a command
 * @command: the command to be executed
 */
void _command(char *command)
{
	pid_t pid;
	int status;
	
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *argv[] = {command, NULL};
		
		execve(command, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

