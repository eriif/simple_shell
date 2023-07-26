#include "shell.h"

/**
 * _strspn - The entry point
 * @s: consists entirely of bytes in accept
 * @accept: the initial segment of s
 *
 * Description: the function that gets the length of a prefix substring
 * Return: usually 0
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int y = 0;
	int z = 0;
	int accept_len = 0;

	while (accept[accept_len])
	{
		accept_len++;
	}
	while (*s)
	{
		z = 0;
		while (accept['r'])
		{
			if (*s == accept[z])
			{
				y++;
				break;
			}
			else if (z == accept_len - 1)
			{
				return (y);
			}
			z++;
		}
		s++;
	}
	return (y);
}

/**
 * _strchr - The function that locates a character in a string.
 * @s: is a string
 * @c: the character to be allocated by a pointer on its
 * first occurrence
 *
 * Return: a pointer to the first occurrence of the character c in the string s
 * or NULL if the character is not found
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

/**
 * free_cmd - frees the cmdline
 * @cmd: double pointer
 */
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
