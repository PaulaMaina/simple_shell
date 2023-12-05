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
