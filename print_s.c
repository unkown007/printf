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
	int size;
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		return (-1);
	size = strlen(s);
	if (write(1, s, size * sizeof(char)) != size)
		return (-1);
	return (size);
}
