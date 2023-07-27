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
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}

/**
* interactive - returns true if shell is interactive mode
* @info: struct address
* Return: 1 if interactive mode, 0 otherwise
**/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - checks if character is a delimeter
* @c: the char to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
**/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* _isalpha - checks for alphabetic character
* @c: The character to input
* Return: 1 if c is alphabetic, 0 otherwise
**/

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
