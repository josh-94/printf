#include "main.h"

/**
 * _printf - function prints int and char.
 * @format: string that contains the format to print.
 * Return: number of characters.
 */

int _printf(const char *format, ...)
{
	char buffer[3000];
	char *ptr = buffer;
	int i = 0;
	va_list parameters;
	/*void (*f)(va_list);*/

	va_start(parameters, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			*ptr = format[i];
			ptr++;
		}
		else
		{
			match(format[i + 1], parameters, &ptr);
			i++;
		}
		i++;
	}
	va_end(parameters);
	_puts(buffer, ptr - (char *)buffer);
	return (ptr - (char *)buffer);
}
/**
 * p_string - function of string
 * @parameters: string
 * @buff: buff
 */

void p_string(va_list parameters, char **buff)
{
	char *ptr = va_arg(parameters, char*);

	while (*ptr != '\0')
	{
		**buff = *ptr;
		(*buff)++;
		ptr++;
	}


}

/**
 * p_char - function of characters
 * @parameters: characters
 * @buff: buff
 */

void p_char(va_list parameters, char **buff)
{
	char c = va_arg(parameters, int);
	**buff = c;
	(*buff)++;

}

/**
 * match - match with the functions respectively.
 * @s: string
 * @parameters: receive parameters
 * @buff: buff
 **/


void match(char s, va_list parameters, char **buff)
{
	int i = 0;
	vars_t func[] = {
		{'s', p_string},
		{'c', p_char},
		{'d', p_integer},
		{'i', p_integer},
		{0, NULL}

	};
	while (func[i].f != NULL)
	{
		if (s == func[i].op)
		{
			func[i].f(parameters, buff);
			return;
		}
		i++;
	}
}
