#include "shell.h"

/**
 * char_compare - compares characters in a string
 * @input_str: input string
 * @delim: delimiter used
 *
 * Return: 1 if the chars are equal, else 0
 */

int char_compare(char input_str[], const char *delim)
{
	unsigned int a, b, c = 0;

	for (a = 0; input_str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (input_str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * custom_strtok - tokenizes the input using a delimiter
 * @input_str: input string
 * @delim: delimiter used to split the string
 *
 * Return: token strings
 */

char *custom_strtok(char input_str[], const char *delim)
{
	static char *token, *end;
	char *start;
	unsigned int c, condition;

	if (input_str != NULL)
	{
		if (char_compare(input_str, delim))
			return (NULL);
		token = input_str;
		c = _strlen(input_str);
		end = &input_str[c];
	}
	start = token;
	if (start == end)
		return (NULL);

	for (condition = 0; *token; token++)
	{
		if (token != start)
		{
			if (*token && *(token - 1) == '\0')
				break;
		}
		for (c = 0; delim[c]; c++)
		{
			if (*token == delim[c])
			{
				*token = '\0';
				if (token == start)
					start++;
				break;
			}
		}
		if (condition == 0 && *token)
			condition = 1;
	}
	if (condition == 0)
		return (NULL);
	return (start);
}
