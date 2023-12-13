#include "shell.h"

/**
 * cd_exec - changes the current directory
 * @env_data: data
 * @env_var: environment variable
 *
 * Return: 1
 */

int cd_exec(info_t *env_data, list_t **env_var)
{
	char *directory;
	int home, home2, isenv;

	directory = env_data->argv[1];

	if (directory != NULL)
	{
		home = custom_strcmp("$HOME", directory);
		home2 = custom_strcmp("~", directory);
		isenv = custom_strcmp("--", directory);
	}
	if (directory == NULL || !home || !home2 || !isenv)
	{
		cd_home(env_data, env_var);
		return (1);
	}

	if (custom_strcmp("-", directory) == 0)
	{
		cd_prev(env_data, env_var);
		return (1);
	}

	if (custom_strcmp(".", directory) || custom_strcmp("..", directory) == 0)
	{
		cd_dots(env_data, env_var);
		return (1);
	}
	cd_dir(env_data, env_var);

	return (1);
}
