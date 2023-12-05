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
	}
	free(buffer);
	return (0);
}
