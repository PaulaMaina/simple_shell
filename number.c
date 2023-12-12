#include "shell.h"
/**
 * num_to_str - converts number to string
 * @a: number passed
 * Return: pointer to string
 */
char *num_to_str(size_t a)
{
	size_t tmp = a, len = 1;
	char *str;
	size_t i;

	while (tmp /= 10)
	{
		len++;
	}
	str = malloc(len + 1);
	if (!str)
	{
		return (NULL);
	}
	str[len] = '\0';
	for (i = len; i > 0; i--)
	{
		str[i - 1] = '0' + a % 10;
		a /= 10;
	}
	return (str);
}

