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
	list_t *env_list = NULL;
	list_t *next = NULL;
	int env_list_size = 0;

	list_t *temp = env_list;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			display_prompt();
			read_count = getline(&buffer, &bufSize, stdin);
			if (custom_strcmp(buffer, "exit") == 0)
			{
				free(buffer);
				free_list_t(env_list);
				exit(EXIT_SUCCESS);
			}
			else if (read_count == -1)
			{
				if (feof(stdin))
				{
					_putchar('\n');
					free(buffer);
					free_list_t(env_list);
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("Getline");
					free(buffer);
					free_list_t(env_list);
					exit(EXIT_FAILURE);
				}
			}
			buffer[read_count - 1] = '\0';
			parse(buffer, read_count);
		}
		while (temp != NULL)
		{
			env_list_size++;
			next = temp->next;
			free(temp->next);
			free(temp);
			temp = next;
		}
		env_list = NULL;
	}
	else
	{
		read_count = getline(&buffer, &bufSize, stdin);
		parse(buffer, read_count);
		free(buffer);
	}
	return (EXIT_SUCCESS);
}
