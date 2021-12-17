#ifndef PRINT_F_H
#define PRINT_F_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * struct vars - structure containing
 * @op: location and method to translate data to characters.
 * @f: print function for specific type.
 */

typedef struct vars
{
	char op;
	void (*f)(va_list, char **buff);
} vars_t;
int _printf(const char *format, ...);
void p_string(va_list parameters, char **buff);
void p_char(va_list parameters, char **buff);
void match(char s, va_list parameters, char **buff);
int _puts(char *buffer, int size);
void p_integer(va_list parameters, char **buff);
void number_to_buff(long int number, char **ffub);
#endif
