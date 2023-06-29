#include "main.h"
/**
 * _printf - print everything
 * @format: specifiers for data types
 * Return: int
 */
int _printf(const char *format, ...)
{
	int (*print_f)(va_list, flags_f *);
	const char *c;

	va_list args;
	flags_f flags = {0, 0, 0};
	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = format; *c; c++)
	{
		if (*c == '%')
		{
			c++;
			if (*c == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*c, &flags))
				c++;
			print_f = get_print(*c);
			count += (print_f)
				? print_f(args, &flags)
				: _printf("%%%c", *c);
		}
		else
			count += _putchar(*c);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
