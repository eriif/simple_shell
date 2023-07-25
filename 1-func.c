#include "shell.h"
/**
 * clear_scrn - inbuilt to clear screen
 */
void clear_scrn(void)
{
	write(STDOUT_FILENO, "\033[2J\033[H", 7);
}
/**
 * exit_shell - exit inbuild
 * @status: the stats
 */
void exit_shell(int status)
{
	write(2, "Exiting...\n", strlen("Exiting...\n"));
	exit(status);
}

/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 *
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *copy;

	int len, i;

	if (strtodup == 0)
		return (NULL);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strtodup[i];

	return (copy);
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: a pointer to a string
 *
 * Return: length
 */
int _strlen(const char *s)
{
	int lngth = 0;

	if (*s)
	{
		lngth++;
		lngth += _strlen(s + 1);
	}

	return (lngth);
}

/**
 * _strcspn - determine the length of the prefix substring
 * @str1: first string
 * @str2: second string
 *
 * Return: count
 */
size_t _strcspn(const char *str1, const char *str2)
{
	const char *p1, *p2;
	size_t count = 0;

	for (p1 = str1; *p1 != '\0'; p1++)
	{
		for (p2 = str2; *p2 != '\0'; p2++)
		{
			if (*p1 == *p2)
				return (count);
		}
		count++;
	}

	return (count);
}
