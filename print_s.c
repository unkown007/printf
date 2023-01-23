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
	int size, r;
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		return (-1);
	size = strlen(s);
	r = write(1, s, size * sizeof(char));
	if (r != size)
		return (r);
	return (size);
}
