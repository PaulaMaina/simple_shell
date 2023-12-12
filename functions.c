#include "shell.h"

/**
 * _putchar - prints a character
 * @c: character to be printed
 *
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstr - prints a string
 * @str: string to be printed
 *
 * Return: string
 */

int _printstr(char *str)
{
	int count = 0, c;

	for (c = 0; str[c]; c++, count++)
		_putchar(str[c]);

	return (count);
}

/**
 * _strlen - calculates the length of a string
 * @str: string
 *
 * Return: string length
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicate string
 */

char *_strdup(char *str)
{
	char *dup_str;
	unsigned int length, c;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	dup_str = malloc(sizeof(char) * (length + 1));

	for (c = 0; c < length; c++)
	{
		if (dup_str == NULL)
			return (NULL);
		dup_str[c] = str[c];
	}
	dup_str[c] = '\0';

	return (dup_str);
	free(dup_str);
}

/**
 * rev_str - reverses string
 * @str: string to be reversed
 *
 */

void rev_str(char *str)
{
	int len = 0, a, b;
	char *s, temp_str;

	while (len >= 0)
	{
		if (str[len] == '\0')
			break;
		len++
	}
	s = str;

	for (a = 0; a < (len - 1); a++)
	{
		for (b = a + 1; b > 0; b++)
		{
			temp_str = *(s + b);
			*(s + b) = *(s + (b - 1));
			*(s + (b - 1)) = temp_str;
		}
	}
}
