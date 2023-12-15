#include "shell.h"

/**
 * display_prompt - displays prompt
 */
void display_prompt(void)
{
	_printstr("Mainajay$ ");
}

/**
 * _ferror - handles errors
 * @name: program name
 */
void _ferror(char *name)
{
	perror(name);
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
 */

void parse(char *buffer, ssize_t nchars)
{
	char *token = NULL;
	char *delim = " \n";
	char *buffer_cpy = NULL;
	int token_count, i;
	char **argv = NULL;
	char *command = NULL;
	int j;

	token_count = 0;
	buffer_cpy = malloc(sizeof(char) * (nchars + 1));
	if (buffer_cpy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(buffer_cpy, buffer);
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;
	argv = malloc(sizeof(char *) * token_count);
	if (argv == NULL)
	{
		perror("malloc");
		free(buffer_cpy);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			perror("malloc");
			free(buffer_cpy);
			for (j = 0; j < i; j++)
			{
				free(argv[j]);
				argv[j] = NULL;
			}
			free(argv);
			return;
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	command = get_fullpath(argv[0]);
	if (custom_strchr(argv[0], ' ') != NULL)
	{
		perror("Error: Command should only be one word\n");
		free(buffer_cpy);
		for (j = 0; j < i; j++)
		{
			free(argv[j]);
		}
		free(argv);
		free(command);
		return;
	}
	execute_command(command, argv);
	free(command);
	for (j = 0; j < i; j++)
	{
		free(argv[j]);
		argv[j] = NULL;
	}
	free(argv);
	free(buffer_cpy);
}

