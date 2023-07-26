#include "shell.h"
int main(void)
{
char *cmd = NULL;
size_t length;
int e_Status = 0;
bool is_tty = isatty(STDIN_FILENO);

while (1)
{
if (is_tty)
write(STDOUT_FILENO, "prompt$ ",
		strlen("prompt$ "));

cmd = _getline(stdin);
if (cmd == NULL)
{
if (is_tty)
write(STDOUT_FILENO, "\n", 1);
break;
}

length = strlen(cmd);
if (length > 0 && cmd[length - 1] == '\n')
{
cmd[length - 1] = '\0';
length--;
}
if (length == 0)
{
free(cmd);
continue;
}

if (strcmp(cmd, "clear") == 0)
{
clear_scrn();
}
else if (strcmp(cmd, "env") == 0)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
else if (strncmp(cmd, "exit", 4) == 0)
{
if (strlen(cmd) > 4)
{
e_Status = atoi(cmd + 5);
}
exit_shell(e_Status);
free(cmd);
break;
}
else
{
char **args = parse_cmd(cmd);
if (args)
{
int status = cmd_execution(args);
free_cmd(args);
if (status < 0)
{
write(STDERR_FILENO, "Failed to execute.\n",
		strlen("Failed to execute.\n"));
}
}
}

free(cmd);
}

return (0);
}
