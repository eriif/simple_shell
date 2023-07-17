#include "shell.h"

/**
 * _strcmp - The compare two string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * @str1: a pointer to the first str
 * @str2: a pointer to the second str to compare the first one with
 * @n: number of chers to be compared
 *
 * Return: 0 for success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t a;

	for (a = 0; a < n; a++)
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}

		if (str1[a] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
/**
 * _atoi - a func that converts a string to integer
 * @str: string to convert
 *
 * Return: the conversion
 */
int _atoi(char *str)
{
	int conv = 0, sign = 0, x = 0;

	if (str[0] == '-')
	{
		sign = (-1);
		x++;
	}
	for (; str[x] != '\0'; x++)
	{
		if (str[x] < '0' || str[x] > '9')
		{
			break;
		}
		conv = conv * 10 + (str[x] - '0');
	}

	return (sign * conv);
}
