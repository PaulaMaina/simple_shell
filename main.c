#include "shell.h"
/**
 * main - Entry point
 * Return: void
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufSize = 0;
	ssize_t read_count;
	list_t *env_list = NULL;
	list_t *next = NULL;
	int env_list_size = 0, exit_status = 0;
	list_t *temp = env_list;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		read_count = getline(&buffer, &bufSize, stdin);
		if (read_count == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}
		if (custom_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			free_list_t(env_list);
			exit(exit_status);
		}
			buffer[read_count - 1] = '\0';
			exit_status = parse(buffer, read_count);
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
	free(buffer);
	return (exit_status);
}

