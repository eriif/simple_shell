#include "shell.h"

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
	int e_Status = 0;
	bool is_tty = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_tty)
			write(STDOUT_FILENO, "prompt$ ", _strlen("prompt$ "));

		cmd = _getline(stdin);
		if (cmd == NULL)
		{
			if (is_tty)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		length = _strlen(cmd);
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
		if (_strcmp(cmd, "clear") == 0)
		{
			clear_scrn();
		}
		else if (_strcmp(cmd, "env") == 0)
		{
			printEnv();
			continue;
		}
		else if (_strncmp(cmd, "exit", 4) == 0)
		{
			if (_strlen(cmd) > 4)
			{
				e_Status = _atoi(cmd + 5);
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
					write(STDERR_FILENO, "Failed to execute.\n", _strlen("Failed to execute.\n"));
				}
			}
		}
		free(cmd);
	}
	return (0);
}
