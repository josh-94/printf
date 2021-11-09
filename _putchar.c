#include "main.h"

int _puts(char *buffer, int size)
{
	return(write(1,buffer,size));
}
