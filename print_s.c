#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_s - print an string to std output
 * @list: argument to be printed
 *
 * Return: number of char printed
 */
int print_s(va_list list)
{
	int i = 0;
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		return (0);
	for (i = 0; s[i]; i++)
		if (write(1, &s[i], sizeof(char)) != 1)
			return (i);
	return (i);
}
