#include "shell.h"

/**
 * _env - Implements the env built-in command
 * @env: A linked list representing the environment variables
 */
void _env(list_t *env)
{
	print_list(env);
}
/**
 * _setenv - Implements the setenv built-in command
 * @env: A linked list representing the environment variables
 * @variable: Name of the environment variable to set or modify
 * @value: Value to set for the environment variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(list_t **env, char *variable, char *value)
{
	char *new;
	list_t *current = *env;

	if (variable == NULL || value == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
		return (-1);
	}
	while (current != NULL)
	{
		if (custom_strcmp(variable, current->var) == 0)
		{
			free(current->var);
			current->var = _strdup(_strcat(variable, _strcat("=", value)));
			if (current->var == NULL)
			{
				write(STDERR_FILENO, "Memory allocation error\n", 24);
				return (-1);
			}
			return (0);
		}
		current = current->next;
	}
	new = _strdup(_strcat(variable, _strcat("=", value)));

	if (new == NULL)
	{
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		return (-1);
		return (-1);
	}
	add_end_node(env, new);
	return (0);
}
/**
 * _unsetenv - Implements the unsetenv built-in command
 * @env: A linked list representing the environment variables
 * @variable: Name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(list_t **env, char *variable)
{
	list_t *current = *env;
	list_t *prev = NULL;

	if (variable == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}
	while (current != NULL)
	{
		if (custom_strcmp(variable, current->var) == 0)
		{
			if (prev == NULL)
			{
				*env = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current->var);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	write(STDERR_FILENO, "Variable not found\n", 19);
	return (-1);
}

