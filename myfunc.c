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
/**
 * _memcpy - a function that copies memory area
 * @dest: The memory area to be copied to
 * @src: The memory area to be copied from
 * @n: The number of bytes
 *
 * Description: The function copies n bytes
 * from memory area src to memory area dest
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a = 0;

	while (a < n)
	{
		(dest[a] = src[a]);
		a++;
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
