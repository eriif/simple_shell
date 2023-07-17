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

int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *_getline(char **cmd, FILE *stream);
void exit_shell(int status);
void clear_scrn();
int main(void);

#endif