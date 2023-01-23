#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * print_c - print a content of char variable
 * @list: list of va arguments
 *
 * Return: number of characters printed
 */
int print_c(va_list list)
{
	char c;

	c = va_arg(list, int);
	if (write(1, &c, sizeof(char)) != 1)
		return (0);
	return (1);
}
