#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
extern char **environ;

/* Function prototypes */
char *_getline(FILE *stream);
char **parse_cmd(char *cmd);
int cmd_execution(char **cmd);
void free_cmd(char **cmd);
void clear_scrn(void);
void exit_shell(int status);

int main(void);

#endif
