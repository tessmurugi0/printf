#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints all characters
 * @format: format
 * Return: prints number of characters
 */
int _printf(const char *format, ...)
{       
        int no_printed = 0;

	va_list args;
        va_start(args, format);
        

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			putchar('%');
			no_printed++;
		}
		else if (*format == 's')
		{
			char *string = va_arg(args, char *);
			while (*string != '\0')
			{
				putchar(*string);
				string++;
				no_printed++;
			}
		}
		else if (*format == 'c')
		{
			int character = va_arg(args, int);
			putchar(character);
			no_printed++;
		}
		else
		{
			putchar(*format);
			no_printed++;
		}
		format++;
	}
	va_end(args);
	return no_printed;
}
