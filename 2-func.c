#include "shell.h"
/**
 * free_cmd - a function that will free args after exe
 * @cmd: args pointer
 */
void free_cmd(char **cmd)
{
	char **ptr = cmd;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(cmd);
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
do {
if (*s == c)
return ((char*)s);
} while (*s++ != '\0');

return (NULL);
}
