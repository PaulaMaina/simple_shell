#include "shell.h"
/**
 * custom_strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if s1 = s2
 */
int custom_strcmp(char *s1, char s2)
{
	int a;
	
	for (a = 0; s1[a] == s2[a] && s1[i] != '\0'; a++)
	{
		;
	}
	if (s2[a] != '\0')
	{
		return (s1[a] - s2[a]);
	}
	else
	{
		return (0);
	}
}
