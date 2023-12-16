#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFSIZE 1024

extern char **environ;

/**
 * struct list_s - Is linked list node to store env variables
 * @var: Is the variable to store
 * @next: Is the pointer to next node
*/
/* Data structure for a linked list node */
typedef struct list_s
{
	char *var;
	struct list_s *next;
} list_t;

/* Function prototypes */
void display_prompt(void);
int execute_command(char *full_path, char **argv, char *command, char *cpy_c);
int parse(char *buffer, ssize_t nchars);
int custom_strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _putchar(char c);
int _printstr(char *str);
int _strlen(char *str);
char *_strdup(char *str);
void rev_str(char *str);
char *get_fullpath(char *command);
char *_strcpy(char *dest, char *src);
char *custom_strchr(const char *str, int a);
void free_list_t(list_t *list);
size_t print_list(list_t *h);
list_t *add_end_node(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, int index);
char *custom_strdup(char *str, int y);
char *find_env(char *str, list_t *env);
void free_args(char *args[]);
ssize_t custom_getline(char **line, size_t *line_size, FILE *stream);
void fetch_line(char **line, size_t *line_size, char *buf, size_t buf_size);
void custom_memcpy(void *dest_ptr, void *src_ptr, unsigned int size);
void *custom_realloc(void *memptr, unsigned int osize, unsigned int nsize);
int char_compare(char input_str[], const char *delim);
char *custom_strtok(char input_str[], const char *delim);
#endif /* SHELL_H */
