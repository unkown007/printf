#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct type - struct type
 * @c: type of output
 * @f: pointer to a function
 */
typedef struct type
{
	char *c;
	char *(*f)(va_list);
} type_t;

int _printf(const char *format, ...);
char *print_c(va_list list);
char *print_s(va_list list);
char *(*get_func(char c, type_t *t))(va_list);

int _isalpha(char c);
int _isupper(char c);
int _position(const char *s, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src, int n);

#endif
