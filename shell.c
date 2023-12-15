#include "shell.h"

/**
 * display_prompt - displays prompt
 */
void display_prompt(void)
{
	_printstr("$ ");
}

/**
 * custom_strchr - locate character in string
 * @str: pointer to the string
 * @a: character to find
 * Return: pointer to the first occurrence of a character or string or null
 */
char *custom_strchr(const char *str, int a)
{
	while (*str != (char)a)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}

/**
 * parse - splits the user input into tokens
 * @buffer: users input
 * @nchars: number of characters in the buffer
 * Return: execution status
 */
int parse(char *buffer, ssize_t nchars)
{
	char *token = NULL, *delim = " \n", *buffer_cpy = NULL, *command = NULL;
	int token_count = 0, i, j, status = 0;
	char **argv = NULL;

	buffer_cpy = malloc(sizeof(char) * (nchars + 1));
	if (buffer_cpy == NULL)
		exit(EXIT_FAILURE);
	_strcpy(buffer_cpy, buffer);
	token = strtok(buffer, delim);
	for (token_count = 0; token != NULL; token_count++)
		token = strtok(NULL, delim);
	argv = malloc(sizeof(char *) * (token_count + 1));
	if (argv == NULL)
		free(buffer_cpy), exit(EXIT_FAILURE);
	token = strtok(buffer_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			free(buffer_cpy);
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			return (1);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL, command = get_fullpath(argv[0]);
	if (command == NULL)
	{
		perror("Error: not found\n");
		free(buffer_cpy), free_args(argv), status = 127;
		return (127);
	}
	status = execute_command(command, argv, buffer_cpy, buffer);
	free(buffer_cpy), free_args(argv), free(command);
	return (status);
}
/**
 * free_args - frees an array of pointer
 * @args: Are the array to free
 * Return void
*/
void free_args(char *args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args[i]);
	free(args);
}

