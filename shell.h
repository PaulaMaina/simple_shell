#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#define BUFSIZE 1024
/*structure to hold exit information*/
/**
 * struct info_t - singly linked list
 * @tokens: array of strings
 * @file: the filename
 * @some_string: additional data
 * @lineno: line number
 * @fileno: an ineteger representing the file number
 * @status: unsigned int representing the exit status
 * @argv: argument vector
 */
typedef struct info_t
{
	char **tokens;
	char *file;
	char *some_string;
	const char *argv;
	size_t lineno;
	int fileno;
	unsigned int status;
} info_t;
bool _isnumber(const char *s);
void _error(const char *name, size_t line, const char *msg, ...);
unsigned int custom_atoi(char *s);
void freeinfo(info_t *info);
int exit(info_t *info);

/**
 * struct list_s - singly linked list
 * @var: string (malloc'ed string)
 * @next: points to the next node
 */
typedef struct list_s
{
	char *var;
	struct list_s *next;
} list_t;

void display_prompt(void);
void _error(char *name, char *message);
void execute_command(char *command, char **argv);
int _putchar(char c);
int _printstr(char *str);
void parse(char *buffer, ssize_t nchars);
int _strlen(char *str);
char *get_fullpath(char *command);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int custom_strcmp(char *s1, char *s2);
void input_command(char *command);
void fetch_line(char **line, size_t *line_size, char *buf, size_t buf_size);
ssize_t custom_getline(char **line, size_t *line_size, FILE *stream);
void custom_memcpy(void *dest_ptr, void *src_ptr, unsigned int size);
void *custom_realloc(void *memptr, unsigned int osize, unsigned int nsize);
size_t print_list(list_t *h);
list_t *add_end_node(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, int index);
void free_list_t(list_t *list);
char *custom_strdup(char *str, int y);
void free_double_p(char **str);
int char_compare(char input_str[], const char *delim);
char *custom_strtok(char input_str[], const char *delim);
int _unsetenv(list_t **env, char *variable);
int _setenv(list_t **env, char *variable, char *value);
void _env(list_t *env);
char *_strcat(char *dest, char *src);
int cd_exec(info_t *env_data);
void cd_dots(infot_t *env_data);
void cd_prev(info_t *env_data);
void cd_home(info_t *env_data);
void cd_dir(info_t *env_data);
void rev_str(char *str);

#endif
