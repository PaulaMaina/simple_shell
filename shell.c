#include "shell.h"

/**
 * display_prompt - displays prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "mainajay$ ", 10);
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
 * execute_command - executes a command
 * @command: the command to be executed
 */
void execute_command(char *command)
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
		char *argv[2];

		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * parse - splits the user input into tokens
 * @buffer: users input
 * @nchars: number of characters in the buffer
 *
 * Return: an array of tokens
 */

char *parse(char *buffer, ssize_t nchars)
{
	char *token, *delim = " \n", *buffer_cpy = NULL;
	int token_count, i;
	char **argv;

	buffer_cpy = malloc(sizeof(char) * nchars);
	if (buffer_cpy == NULL)
	{
		free(buffer);
		perror("Memory allocation failed\n");
		exit(98);
	}

	strcpy(buffer_cpy, buffer);
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;
	argv = malloc(sizeof(char *) * token_count);
	token = strtok(buffer_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char *) * _strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	free(argv);
	free(buffer_cpy);
	free(buffer);
	return (*argv);

}
