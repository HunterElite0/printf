#include "main.h"
/**
 * get_size - returns size
 *
 * @str: string
 *
 * Return: int
*/
int get_size(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
