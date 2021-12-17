#include "main.h"
/**
 * _puts - function for putchar
 * @buffer: buff
 * @size: size of buffer
 * Return: buff
 */
int _puts(char *buffer, int size)
{
	return (write(1, buffer, size));
}
