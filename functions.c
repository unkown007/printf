#include "main.h"

/**
 * _isalpha - test if a char is alpha
 * @c: character
 *
 * Return: 1 (success), 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 65 && c <= 90) ||
		(c >= 97 && c <= 122))
		return (1);
	return (0);
}

/**
 * _isupper - checks if a char is uppercase
 * @c: character
 *
 * Return: 1 (success), 0 otherwise
 */
int _isupper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

/**
 * _position - return position on string
 * @s: string
 * @n: int
 * Return: postion on string
 */
int _position(const char *s, int n)
{
	int i;

	i = 0;

	while (*s)
	{
		if (s[n + 1] != ' ')
		{
			return (i);
		}
		n++;
		i++;
	}
	return (0);
}

/**
 * _strlen - string length
 * @s: string
 * Return: length of string int
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: char pointer
 * @src: char pointer
 * @n: int
 * Return: char pointer
 */
char *_strcat(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return (dest);
}
