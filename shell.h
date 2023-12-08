#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFSIZE 1024

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
int custom_strcmp(char *s1, char s2);
void input_command(char *command);
void fetch_line(char **line, size_t *line_size, char *buf, size_t buf_size);
ssize_t custom_getline(char **line, size_t *line_size, FILE stream);
void custim_memcpy(void *dest_ptr, void *src_ptr, unsigned int size);
void *custom_realloc(void *memptr, unsigned int osize, unsigned int nsize);

#endif
