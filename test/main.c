<<<<<<< HEAD
#include "shell.h"

/**
 * main - executes the simple shell functions
 * @ac: argument count
 * @av: argument vector
 *
 * Return: On success 0
 */

int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t nchars = 0;

	(void) ac, (void) av;
	while (1)
	{
		_prompt();
		nchars = getline(&buffer, &size, stdin);

		if (nchars == -1)
		{
			_printstr("Exiting shell...\n");
			return (-1);
		}
		_printstr(buffer);
		parse(buffer, nchars);
=======
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t read_count;

	/* Check if running interactively */
	if (isatty(STDIN_FILENO))
	{
		/* Interactive mode */
		while (1)
		{
			/* Display the shell prompt */
			display_prompt();

			read_count = getline(&buffer, &bufsize, stdin);

			if (read_count == -1)
			{
				/* Handle end of file condition (Ctrl+D) */
				if (feof(stdin))
				{
					write(STDOUT_FILENO, "\n", 1);
					free(buffer);
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("getline");
					free(buffer);
					exit(EXIT_FAILURE);
				}
			}

			buffer[read_count - 1] = '\0';
			printf("%s\n", buffer);

			execute_command(buffer);
		}
	}
	else
	{
		/* Non-interactive mode */
>>>>>>> 40b09a46f9425c1ee0959e551319e4fb450fd258
	}
	free(buffer);
	return (0);
}
<<<<<<< HEAD
=======

>>>>>>> 40b09a46f9425c1ee0959e551319e4fb450fd258
