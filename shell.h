#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdarg.h>

extern char **environ;

/*  Prototypes that will return int */
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
int _unsetenv(char *var);
int _setenv(const char *name, const char *value, int overwrite);
int main(void);
int exe_with_args(char *cmd);
int _strlen(const char *s);
int cmd_execution(char **cmd);

/*  Prototypes that will return char  */
char *_getline(char **cmd, FILE *stream);
char *_strdup(char *strtodup);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, const char *src);

/*  Prototypes that wont return anything */
void exit_shell(int status);
void clear_scrn();
void printEnv(void);

size_t _strcspn(const char *str1, const char *str2);
unsigned int _strspn(char *s, const char *accept);

#endif