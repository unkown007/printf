#include "main.h"

/**
 * print_c - print a content of char variable
 * @list: list of va arguments
 *
 * Return: character to be printed
 */
char *print_c(va_list list)
{
	static char c[2] = {0, '\0'};

	c[0] = va_arg(list, int);
	if (c[0] == '\0')
		return (" ");
	return (c);
}

/**
 * print_s - print an string to std output
 * @list: argument to be printed
 *
 * Return: pointer to arg
 */
char *print_s(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		return (s = "(null)");
	return (s);
}
