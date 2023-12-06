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
 * input_command - a function that executes the exit command
 * @command: the command to be executed
 */
void input_command(char *command)
{
	if (custom_strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * parse - splits the user input into tokens
 * @buffer: users input
 * @nchars: number of characters in the buffer
 */

void parse(char *buffer, ssize_t nchars)
{
	char *token, *delim = " \n", *buffer_cpy = NULL;
	int token_count, i;
	char **argv, *command = NULL;

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
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	command = get_fullpath(argv[0]);
	execute_command(command, argv);
	free(argv);
	free(buffer_cpy);
}
