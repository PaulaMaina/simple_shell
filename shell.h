#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

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
#endif
