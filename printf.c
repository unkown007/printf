#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format of the output
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, j;
	int len = 0;
	char *s;
	char *buffer;

	type_t type_out[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		return (-1);
	}
	va_start(list, format);
	if (format == NULL || list == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
			continue;
		else if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
				i += _position(format, i);
			for (j = 0; type_out[j].f != NULL; j++)
			{
				if (format[i + 1] == *(type_out[j].c))
				{
					s = type_out[j].f(list);
					if (s == NULL)
						return (-1);
					_strlen(s);
					_strcat(buffer, s, len);
					len += _strlen(s);
					i++;
					break;
				}
			}
			if (type_out[j].f == NULL)
			{
				buffer[len] = format[i];
				len++;
			}
		}
		else
		{
			buffer[len] = format[i];
			len++;
		}
	}
	buffer[len] = '\0';
	write(1, buffer, len);
	va_end(list);
	free(buffer);
	return (len);
}
