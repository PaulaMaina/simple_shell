#include "shell.h"

/**
 * get_fullpath - gets the environment variable
 * @command: name of the argument
 *
 * Return: pointer to the full path of the command
 */

char *get_fullpath(char *command)
{
	char *pathname = NULL;
	char *cpy_pathname = NULL;
	char *token_path = NULL;
	char *full_path = NULL;
	char *delim = ":";
	int command_len, dir_length;
	struct stat buffer;

	pathname = getenv("PATH");
	if (pathname)
	{
		cpy_pathname = _strdup(pathname);
		command_len = _strlen(command);
		token_path = strtok(cpy_pathname, delim);
		while (token_path != NULL)
		{
			dir_length = _strlen(token_path);
			full_path = malloc(sizeof(char) * (command_len + dir_length + 2));
			if (full_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
				return (NULL);
			}
			_strcpy(full_path, token_path);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (stat(full_path, &buffer) == 0)
			{
				free(cpy_pathname);
				return (full_path);
			}
			else
			{
				free(full_path);
				token_path = strtok(NULL, delim);
			}
		}
		free(cpy_pathname);
		if (stat(command, &buffer) == 0)
			return (command);
	}
	return (NULL);
}
