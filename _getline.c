#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - read line of text from the user's input and use it in a program
 * @stream: the file to read from
 *
 * Return: -1 on failure or when it's an invalid arg.
 */
char *_getline(FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static int index = 0, bytesRead = 0;
	char c, *newCmd;
	int Lsize = 0, currentBuff = BUFFER_SIZE;

	char *cmd = malloc(currentBuff * sizeof(char));
	if (cmd == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (index == bytesRead)
		{
			bytesRead = read(fileno(stream), buffer, BUFFER_SIZE);
			if (bytesRead == -1)
			{
				perror("Error from read");
				exit(EXIT_FAILURE);
			}
			if (bytesRead == 0)
				break;
			index = 0;
		}
		c = buffer[index++];
		if (c == '\n')
		{
			cmd[Lsize] = '\0';
			break;
		}
		if (Lsize + 1 == currentBuff)
		{
			currentBuff *= 2;
			newCmd = realloc(cmd, currentBuff * sizeof(char));
			if (newCmd == NULL)
			{
				free(cmd);
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			cmd = newCmd;
		}
		cmd[Lsize] = c;
		Lsize++;
	}
	return (cmd);
}

/**
 * _strtok - short desc
 * @str: what it does
 * @delim: what it does
 *
 * Return: what is returned
 */
/**char *_strtok(char *str, const char *delim)
{
	static char* buffer = NULL;
	size_t token_start = _strspn(buffer, delim);
	size_t token_end = _strcspn(buffer + token_start, delim);

	if (str != NULL)
	{
		buffer = str;
	}
	if (buffer == NULL || *buffer == '\0')
	{
		return (NULL);
	}
	if (buffer[token_start] == '\0')
	{
		buffer = buffer + token_start;
		return (NULL);
	}
	if (buffer[token_start + token_end] != '\0')
	{
		buffer[token_start + token_end] = '\0';
		buffer = buffer + token_start + token_end + 1;
	}
	else
	{
		buffer = buffer + token_start + token_end;
	}
	return (buffer - token_end - token_start);
}

char **tokenize_input(char *cmd)
{
	char *token = NULL;
	char *delim = " \t\r\n\a";
	int number_tokens = 0;
	int i, s = 0;
	char **argv;

	token = _strtok(cmd, delim);
	while (token != NULL)
	{
		number_tokens++;
		token = _strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (number_tokens + 1));
	if (argv == NULL)
	{
		return (NULL);
	}

	token = _strtok(cmd, delim);
	for (i = 0; token != NULL; i++)
	{
		s = strlen(token);
		argv[i] = malloc(sizeof(char) * (s + 1));
		if (argv[i] == NULL)
		{
			for (; i > 0; i--)
			{
				free(argv[i - 1]);
				free(argv);
				return (NULL);
			}
		}
		strcpy(argv[i], token);
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}**/