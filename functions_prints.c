#include "main.h"
/**
 * number_to_buff - parameters function.
 * @number: number
 * @ffub: ffub
 */

void number_to_buff(long int number, char **ffub)
{
	long int num;
	long int r;
	int i;/*iterador para obtener f*/
	int b; /*Contador de dígitos*/
	long int f; /*potencia de 10*/
	int t;/*Extrae digito por digito y lo agrega al buffer*/

	b = 1;
	f = 1;

	if (number < 0)
	{
		**ffub = '-';
		num = -number;
		(*ffub)++;
	} else
	{
		num = number;
	}
	r = num;
	while (num / 10 >= 1)/*contador de digitos = b*/
	{
		num = num / 10;
		b++;
	}
	for (i = 1 ; i < b ; i++)/*potencia de 10*/
	{
		f *= 10;
	}
	while (b > 1 || f > 0)/*asigna digito por digito al buffer*/
	{
		t = (r / f) % 10;
		f /= 10;
		**ffub = t + '0';
		(*ffub)++;
		b--;
	}
}

/**
 * p_integer - functions
 * @parameters: value
 * @buff: buff
 */
void p_integer(va_list parameters, char **buff)
{
	int number  = va_arg(parameters, int);

	number_to_buff(number, buff);
}
