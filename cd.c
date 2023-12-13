#include "shell.h"

/**
 * cd_dots - changes directory to parent directory
 * @env_data: data
 * @env_var: environment variable
 *
 */

void cd_dots(info_t *env_data, list_t **env_var)
{
	char parent_dir[PATH_MAX], *directory;
	char *parent_cp, *parent_strtok;

	getcwd(parent_dir, sizeof(parent_dir));
	parent_cp = _strdup(parent_dir);
	_setenv(env_var, parent_cp, "OLDPWD");
	directory = env_data->argv[1];
	if (custom_strcmp(".", directory) == 0)
	{
		_setenv(env_var, parent_cp, "PWD");
		free(parent_cp);
	}
	if (custom_strcmp("/", parent_cp) == 0)
		free(parent_cp);
	parent_strtok = parent_cp;
	rev_str(parent_strtok);
	parent_strtok = custom_strtok(parent_strtok, "/");
	if (parent_strtok != NULL)
	{
		chdir(parent_strtok);
		_setenv(env_var, parent_strtok, "PWD");
	}
	else
	{
		chdir("/");
		_setenv(env_var, "/", "PWD");
	}
	env_data->status = 0;
	free(parent_cp);
}

/**
 * cd_prev - reverts to the previous directory
 * @env_data: data
 * @env_var: environment variable
 *
 */
void cd_prev(info_t *env_data, list_t **env_var)
{
	char parent_dir[PATH_MAX], *parent_cp;
	char *parent_p, *oldparent_p, *cp_oldparent;
	list_t *var = *env_var;

	getcwd(parent_dir, sizeof(parent_dir));
	parent_cp = _strdup(parent_dir);

	oldparent_p = find_env("OLDPWD", var);

	if (oldparent_p == NULL)
		cp_oldparent = parent_cp;
	else
		cp_oldparent = _strdup(oldparent_p);
	_setenv(env_var, parent_cp, "OLDPWD");

	if (chdir(cp_oldparent) == -1)
		_setenv(env_var, parent_cp, "PWD");
	else
		_setenv(env_var, cp_oldparent, "PWD");

	parent_p = find_env("PWD", var);

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
 * @env_var: environment variable
 *
 */

void cd_home(info_t *env_data, list_t **env_var)
{
	char parent_dir[PATH_MAX], *parent_p, *ishome;
	list_t *var = *env_var;

	getcwd(parent_dir, sizeof(parent_dir));
	parent_p = _strdup(parent_dir);

	ishome = find_env("HOME", var);
	if (ishome == NULL)
	{
		_setenv(env_var, parent_p, "OLDPWD");
		free(parent_p);
	}

	if (chdir(ishome) == -1)
	{
		perror("No such file or directory");
		free(parent_p);
	}

	_setenv(env_var, parent_p, "OLDPWD");
	_setenv(env_var, ishome, "PWD");
	free(parent_p);
	env_data->status = 0;
}

/**
 * cd_dir - changes directory to the given one
 * @env_data: data
 * @env_var: environment variable
 *
 */

void cd_dir(info_t *env_data, list_t **env_var)
{
	char parent_dir[PATH_MAX], *directory, *parent_cp, *directory_cp;

	getcwd(parent_dir, sizeof(parent_dir));

	directory = env_data->argv[1];

	if (chdir(directory) == -1)
		perror("No such directory found");

	parent_cp = _strdup(parent_dir);
	_setenv(env_var, parent_cp, "OLDPWD");

	directory_cp = _strdup(directory);
	_setenv(env_var, directory_cp, "PWD");

	free(parent_cp);
	free(directory_cp);

	env_data->status = 0;

	chdir(directory);
}
