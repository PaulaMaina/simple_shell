#include "shell.h"

/**
 * cd_dots - changes directory to parent directory
 * @env_data: data
 *
 */

void cd_dots(info_t *env_data)
{
	char parent_dir[PATH_MAX], *directory;
	char *parent_cp, *parent_strtok;

	getcwd(parent_dir, sizeof(parent_dir));
	parent_cp = custom_strdup(parent_dir);
	_setenv("OLDPWD", parent_cp, env_data);
	directory = env_data->argv[1];
	if (custom_strcmp(".", directory) == 0)
	{
		_setenv("PWD", parent_cp, env_data);
		free(parent_cp);
	}
	if (custom_strcmp("/", parent_cp) == 0)
		free(parent_cp);
	parent_strtok = parent_cp;
	rev_str(parent_strtok);
	parent_strtok = custom_strtok(parent_strtok, "/");
	if (parent_strtok != NULL)
	{
		chdir(parent_strok);
		_setenv("PWD", parent_strtok, env_data);
	}
	else
	{
		chdir("/");
		_setenv("PWD", "/", env_data);
	}
	env_data->status = 0;
	free(parent_cp);
}

/**
 * cd_prev - reverts to the previous directory
 * @env_data: data
 *
 */
void cd_prev(info_t *env_data)
{
	char parent_sir[PATHMAX], *parent_cp;
	char *parent_p, oldparent_p, cp_oldparent;

	getcwp(parent_dir, sizeof(parent_dir));
	parent_cp = custom_strdup(parent_dir);

	oldparent_p = find_end("OLDPWD", info_t->some_string);

	if (oldparent_p == NULL)
		cp_oldparent = parent_cp;
	else
		cp_oldparent = custom_strdup(oldparent_p);
	_setenv("OLDPWD", parent_cp, env_data);

	if (chdir(cp_oldparent) == -1)
		_setenv("PWD", parent_cp, env_data);
	else
		_setenv("PWD", cp_oldparent, env_data);

	parent_p = find_env("PWD", info_t->some_string);

	write(STDOUT_FILENO, parent_p, _strlen(parent_p));
	write(STDOUT_FILENO, "\n", 1);

	free(parent_cp);
	if (oldparent_p)
		free(cp_oldparent);
	env_data->status = 0;

	chdir(parent_p);
}

/**
 * cd_home - change to home directory
 * @env_data: data
 *
 */

void cd_home(info_t *env_data)
{
	char parent_dir[PATHMAX], *parent_p, *ishome;

	getcwd(parent_dir, env_data->some_string);
	parent_p = custom_strdup(parent_dir);

	ishome = find_env("HOME", info_t->some_string);
	if (ishome == NULL)
	{
		_setenv("OLDPWD", parent_p, env_data);
		free(parent_p);
	}

	if (chdir(ishome) == -1)
	{
		_error(env_data, 2);
		free(parent_p);
	}

	_setenv("OLDPWD", parent_p, env_data);
	_setenv("PWD", ishome, env_data);
	free(parent_p);
	env_data->status = 0;
}

/**
 * cd_dir - changes directory to the given one
 * @env_data: data
 *
 */

void cd_dir(info_t *env_data)
{
	char parent_dir[PATH_MAX], *directory, *parent_cp, *directory_cp;

	getcwd(parent_dir, sizeof(parent_dir));

	directory = env_data->argv[1];

	if (chdir(directory) == -1)
		_error(env_data, 2);

	parent_cp = custom_strdup(parent_dir);
	_setenv("OLDPWD", parent_cp, env_data);

	directory_cp = custom_strdup(directory);
	_setenv("PWD", directory_cp, env_data);

	free(parent_cp);
	free(directory_cp);

	env_data->status = 0;

	chdir(directory);
}
