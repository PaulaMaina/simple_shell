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
	ssize_t read_count;	/* char *user_var; */
	list_t *env_list;

	if (isatty(STDIN_FILENO))
	{	/* Interactive mode */
		while (1)
		{	/* Display the shell prompt */
			display_prompt();
			read_count = getline(&buffer, &bufSize, stdin);
			if (custom_strcmp(buffer, "exit") == 0)
				free(buffer), exit(EXIT_SUCCESS);
			else if (read_count == -1)
			{	/* Handle end of file condition (Ctrl + D) */
				if (feof(stdin))
				{
					_putchar('\n'), free(buffer), exit(EXIT_SUCCESS);
				}
				else
				{
					perror("Getline");
					free(buffer), exit(EXIT_FAILURE);
				}
			}
			buffer[read_count - 1] = '\0';
			parse(buffer, read_count);
		}
		env_list = NULL;
		add_end_node(&env_list, "PATH=/usr/bin");
		add_end_node(&env_list, "HOME=/home/user");
		add_end_node(&env_list, "USER=user");
	}
	else
	{
		read_count = getline(&buffer, &bufSize, stdin);
		parse(buffer, read_count);
	}
	free(buffer);
	return (0);
}
