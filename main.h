#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct type - struct type
 * @c: type of output
 * @f: pointer to a function
 */
typedef struct type
{
	char *c;
	int (*f)(va_list);
} type_t;

int _printf(const char *format, ...);
int print_c(va_list list);
int print_s(va_list list);
int (*get_func(char c, type_t *t))(va_list);

#endif
