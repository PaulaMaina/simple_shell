#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: resulting string
 * @src: original string
 *
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int length, c;

	length = _strlen(dest);

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[length] = src[c];
		length++;
	}
	dest[length] = '\0';

	return (dest);
}
