#include "shell.h"

/**
 * cmd_execution - executs commands specified
 * @cmd: a character pointer of the commands
 *
 * Description: this func executes a command specified user in cmd,
 * The function replaces the current process with new ones specified
 * and arguments.the parent waits for child process to finish
 * but when an error is encountered it exits with 1.
 *
 * Return: -1 when forking fails and the status of chiled process
 */
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
 * parse_cmd - the entry point
 * @cmd: commands
 *
 * Return: aguments
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
		args[arg_count] = _strdup(token);
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
