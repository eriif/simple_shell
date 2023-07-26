#include "shell.h"

/**
 * cmd_execution - Free the memory used by the array of command arguments.
 * @cmd: The array of command arguments to free.
 *
 * This function frees the memory allocated for each argument in the array
 * and then frees the array itself.
 * Return: -1 on success
 **/
int cmd_execution(char **cmd)
{
pid_t pid;
int status = 0;

pid = fork();
if (pid < 0)
{
perror("fork error");
return (-1);
}
else if (pid == 0)
{
/* This part will handle the child process */
execvp(cmd[0], cmd);
perror("Failed to execute");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
return (status);
}
/**
 * free_cmd - clear the command line
 * clear_scrn - Clear the terminal screen.
 * @cmd: The array of command arguments
 * This function sends escape sequences to the terminal to clear the screen.
 **/

void free_cmd(char **cmd)
{
char **ptr = cmd;
while (*ptr != NULL)
{
free(*ptr);
ptr++;
}
free(cmd);
}
/**
 * clear_scrn - Clear the terminal screen
 * exit_shell - Exit the shell program with a given status.
 * @status: The exit status to use.
 * This function prints a message indicating the shell is exiting and then
 * exits the shell program with the provided status.
 **/
void clear_scrn(void)
{
write(STDOUT_FILENO, "\033[2J\033[H", 7);
}
void exit_shell(int status)
{
write(STDERR_FILENO, "Exiting...\n", strlen("Exiting...\n"));
exit(status);
}
