#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - read line of text from the user's input and use it in a program
 * @cmd: double pointer
 * @stream: the file to read from
 *
 * Return: -1 on failure or when it's an invalid arg.
 */
char *_getline(char **cmd, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static int index;
	static int bytesRead;
	static int currentBuff = BUFFER_SIZE;
	char c;
	char *newCmd;
	int Lsize = 0;

	if (*cmd == NULL)
	{
		*cmd = malloc(currentBuff * sizeof(char));
		if (*cmd == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
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
			(*cmd)[Lsize] = '\0';
			break;
		}
		if (Lsize + 1 == currentBuff)
		{
			currentBuff *= 2;
			newCmd = malloc(currentBuff * sizeof(char));
			if (newCmd == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			_memcpy(newCmd, *cmd, Lsize);
			free(*cmd);
			*cmd = newCmd;
		}
		(*cmd)[Lsize] = c;
		Lsize++;
	}
	return (*cmd);
}

/**
 * _strtok - short desc
 * @str: what it does
 * @delim: what it does
 *
 * Return: what is returned
 */
char* _strtok(char* str, const char* delim)
{
	static char* buffer = NULL;
	size_t token_start = _strspn(buffer, delim);

	if (str != NULL)
	{
		buffer = str;
	}
	if (buffer == NULL || *buffer == '\0')
	{
		return (NULL);
	}
	size_t token_end = _strcspn(buffer + token_start, delim);
	
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
