#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * get_func - get the pointer to a function
 * @c: type
 * @t: list of types and corresponding functions
 *
 * Return: pointer to a function or NULL
 */
int (*get_func(char c, type_t *t))(va_list)
{
	int i;

	for (i = 0; t[i].c != NULL; i++)
		if (c == *(t[i].c))
			return (t[i].f);
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: format of the output
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, count, r;
	int (*f)(va_list);
	type_t type_out[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	if (format == NULL || *format == '\0')
		return (0);

	va_start(list, format);
	i = count = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			if (write(1, &format[i], sizeof(char)) != 1)
				return (count);
			count++;
			i++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			f = get_func(format[i], type_out);
			r = f(list);
			count += r;
			i++;
		}
	}
	va_end(list);
	return (count);
}
