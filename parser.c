#include "shell.h"
/**
 * parse_cmd - command to parse
 * @cmd: command line
 * Return: command parsed
 */
char **parse_cmd(char *cmd)
{
char **args = NULL;
char *token = strtok(cmd, " \t\n");
int arg_count = 0;

while (token != NULL)
{
args = realloc(args, (arg_count + 1) * sizeof(char *));
if (args == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
args[arg_count] = strdup(token);
if (args[arg_count] == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
arg_count++;
token = strtok(NULL, " \t\n");
}

args = realloc(args, (arg_count + 1) * sizeof(char *));
if (args == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
args[arg_count] = NULL;

return (args);
}
