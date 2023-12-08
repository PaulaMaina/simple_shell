#include "shell.h"
/**
 * custom_strdup - custom string duplication; excludes bytes at the begining
 * @str: string
 * @y: bytes to be excluded (example ("PATH=")
 * Return: the duplicated string
 */
char *custom_strdup(char *str, int y)
{
	int len = 0;
	int i;
	char *duplicate_str;

	if (str == NULL) /* validate inputString */
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	len++;

    /* allocate memory but exclude environmental variable title (PATH) */
	duplicate_str = malloc(sizeof(char) * (len - y + 1));
	if (duplicate_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len - y; i++)
	{
		duplicate_str[i] = str[y + i];
	}
	duplicate_str[len - y] = '\0';
	return (duplicate_str);
}

/**
 * find_env - finds a copy of the environment variable
 * @str: string
 * @env: a set ofenvironmental variables
 * Return: a copy of the variable
 */
char *find_env(char *str, list_t *env)
{
	int b, y;

	b = 0;
	y = 0;

	if (env == NULL || str == NULL)
	{
		return (NULL);
	}
	while (env != NULL)
	{
		b = 0;
		while (env->var[b] == str[b]) /* gets desired env variable */
		{
			b++;
		}
		if (str[b] == '\0' && env->var[b] == '=')
		{
			break;
		}
		env = env->next;
	}
	while (str[y] != '\0') /* find how many bytes in env variable title */
	{
		y++;
	}
	y++;
	if (env == NULL || env->var == NULL)
	{
		return (NULL);
	}
	return (custom_strdup(env->var, y)); /* make a copy of variable w/o title */
}
