#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: void
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufSize = 0;
	ssize_t read_count;

	if (isatty(STDIN_FILENO))
	{	/* Interactive mode */
		while (1)
		{	/* Display the shell prompt */
			display_prompt();
			read_count = custom_getline(&buffer, &bufSize, stdin);
			if (custom_strcmp(buffer, "exit") == 0)
			{
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			else if (read_count == -1)
			{	/* Handle end of file condition (Ctrl + D) */
				if (feof(stdin))
				{
					_putchar('\n');
					free(buffer);
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("Getline");
					free(buffer);
					exit(EXIT_FAILURE);
				}
			}
			buffer[read_count - 1] = '\0';
			parse(buffer, read_count);
			/* execute_command(buffer); */
		}
	}
	else
	{	/* Non-interactive mode */
	}
	free(buffer);
	return (0);
}
