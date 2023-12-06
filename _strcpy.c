#include "shell.h"

/**
 * _strcpy - copies a string
 * @src: original string
 * @dest: copied string
 *
 * Return: pointer to copied string
 */

char *_strcpy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c] != '\0'; c++)
		dest[c] = src[c];
	dest[c] = '\0';

	return (dest);
}
