#ifndef SHELL_H
#define SHELL_H

/*#define BUFFER_SIZE 1024*/

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

int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *_getline(char **cmd, FILE *stream);
void exit_shell(int status);
void clear_scrn();
char *_getenv(const char *name);
void printEnv(void);
int _unsetenv(char *var);
int _setenv(const char *name, const char *value, int overwrite);
char *_memcpy(char *dest, char *src, unsigned int n);
int cmd_execution(char *cmd);
char *_strcat(char *dest, const char *src);
int main(void);

#endif