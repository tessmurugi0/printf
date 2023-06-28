#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
int _printf(const char *format, ...)
{
	int num_printed = 0;

    va_list args;
    va_start(args, format);


    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'd':
                case 'i':
                {
                    int value = va_arg(args, int);
                    char buffer[12];
                    int length = sprintf(buffer, "%d", value);
                    fputs(buffer, stdout);
                    num_printed += length;
                    break;
                }
                case 'c':
                {
                    int character = va_arg(args, int);
                    putchar(character);
                    num_printed++;
                    break;
                }
                case 's':
                {
                    char *string = va_arg(args, char *);
                    fputs(string, stdout);
                    num_printed += strlen(string);
                    break;
                }
                case '%':
                {
                    putchar('%');
                    num_printed++;
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    num_printed += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            num_printed++;
        }

        format++;
    }

    va_end(args);
    return (num_printed);
}
