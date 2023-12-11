#include "shell.h"
/**
 * _isnumber - confirms if a string is made up of numbers
 * @s: string
 * Return: true or false
 */

bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s < '0' || *s > '9')
			{
				return (false);
				s++;
			}
			return (true);
		}
		return (false);
	}
}
/**
 * _error - prints a message to standard error
 * @name: vector
 * @line: line number where the error occured
 * @msg: error message
 * @...: additional arguments
 */
void _error(const char *name, size_t line, const char *msg, ...)
{
	va_list args;
	char *linestr;

	if (name)
	{
		while (name)
		{
			write(STDERR_FILENO, arg0, 1);
			name++;
		}
		write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, " ", 1);
	}
	linestr = num_to_str(line);
	if (linestr)
	{
		while (*linestr)
		{
			write(STDERR_FILENO, linestr, 1);
			linestr++;
		}
		write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, " ", 1);
		free(linestr);
	}
	va_start(args, msg);
	while (*msg)
	{
		write(STDERR_FILENO, msg, 1);
		msg++;
	}
	va_end(args);
	write(STDERR_FILENO, "\n", 1);
}
/**
 * custom_atoi - function that converts a string to an integer
 * @s: string
 * Return: unsigned integer if successful
 */
unsigned int custom_atoi(char *s)
{
	unsigned int result = 0;
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > (UINT_MAX - (s[i] - '0')) / 10)
		{
			return (UINT_MAX);
		}
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}
/**
 * freeinfo - frees malloced info
 * @info: the infomartion passed
 */
void freeinfo(info_t *info)
{
	int i;

	if (info->tokens != NULL)
	{
		for (i = 0; info->tokens[i] != NULL; i++)
		{
			free(info->tokens[i]);
		}
		free(info->tokens);
	}
	if (info->file != NULL)
	{
		free(info->file);
	}
	if (info->some_string != NULL)
	{
		free(info->some_string);
	}
	free(info);
}
/**
 * exit - hendles the exit of a program form the shell
 * @info: information passed
 * Return: no return value
 */
int exit(info_t *info)
{
	char **args = info->tokens + 1;
	unsigned int status;

	if (*args)
	{
		status = custom_atoi(*args);
		if (status != UINT_MAX)
		{
			info->status = status;
		}
		else
		{
			_error(*info->argv, info->lineno, *args,
					*info->tokens, "Illegal number", NULL);
			info->status = 2;
			return (info->status);
		}
	}
	if (info->file)
	{
		close(info->fileno);
	}
	exit(freeinfo(info));
}

