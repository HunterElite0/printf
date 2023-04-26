#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: size
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	int len = 0;
	char buf[1024];
	char *str;
	va_list v;

	va_start(v, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				switch (format[i + 1])
				{
				case 'c':
					buf[0] = va_arg(v, int);
					write(1, buf, 1);
					i += 2;
					break;
				case 's':
					str = va_arg(v, char *);
					len = get_LenOfString(str);
					for (j = 0; j < len; j++)
					{
						buf[0] = str[j];
						write(1, buf, 1);
					}
					i += 2;
					break;
				}
			}
			buf[0] = format[i];
			write(1, buf, 1);
			i++;
		}
	}
	printf("\n");
	va_end(v);
	return (len);
}
