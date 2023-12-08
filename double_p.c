#include "shell.h"
/**
 * free_double_p - frees an array of malloced strings
 * @str: array of strings to be freed
 */
void free_double_p(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}

