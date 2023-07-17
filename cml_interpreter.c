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
int cmd_execution(char *cmd)
{
	pid_t pid = fork();
	int status;
	char *args[2];

	args[0] = cmd;
	args[1] = NULL;

	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd, args, NULL) < 0)
		{
			write(2, "./hsh: Failed to execute.\n",
					strlen("./hsh: Failed to execute.\n"));
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		return (status);
	}
	return (0);
}

/**
 * main - the entry point
 *
 * Description: The function reads inputs from the user.
 * The function uses a boolean which is combined by the isatty func in the...
 * while loop to check if the stdout is not in the terminal to make the...
 * prompt$ apear only ones.
 * the func also checks whether their is no input by the user where it will...
 * continue to display the prompt again.
 * it also checks the input by the user and when it finds a space at the end...
 * then it removes it to '\0'.
 *
 * Return: 0 for (success).
 */
int main(void)
{
	char *cmd = NULL;
	size_t length;
	bool F = false;

	while (1 && !F)
	{
		if (isatty(STDIN_FILENO) == 0)
			F = true;
		if (true != F)
			write(1, "prompt$ ", strlen("prompt$ "));
		if (_getline(&cmd, stdin) == NULL)
		{
			write(1, "\n", 1);
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
			continue;
		}
		if (cmd_execution(cmd) < 0)
		{
			write(2, "Failed to execute.\n",
					strlen("Failed to execute.\n"));
		}
	}

	free(cmd);
	return (0);
}
