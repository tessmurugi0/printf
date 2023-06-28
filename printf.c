#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, count = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			continue;
		}

		j = i + 1;

		while (format[j] == ' ')
			j++;

		if (format[j] == '\0')
			return (-1);

		func = NULL;

		while (format[j] != '\0')
		{
			int k = 0;

			while (print_formats[k].format != NULL)
			{
				if (*(print_formats[k].format) == format[j])
				{
					func = print_formats[k].print_func;
					break;
				}

				k++;
			}

			if (func != NULL)
				break;

			if (format[j] == '\0')
				return (-1);

			_putchar(format[i]);
			count++;
			i = j;
			j++;

			while (format[j] == ' ')
				j++;
		}

		if (func != NULL)
		{
			count += func(args);
			i = j;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}
