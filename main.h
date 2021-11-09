#ifndef PRINT_F_H
#define PRINT_F_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct vars
{
	char op;
	void (*f)(va_list, char *buff);
} vars_t;
int _printf(const char *format, ...);
void p_string(va_list parameters, char *buff);
void p_char(va_list parameters, char *buff);
 void match(char s,va_list parameters, char *buff);
int _puts(char *buffer, int size);

#endif
