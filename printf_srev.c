#include "main.h"
/**
 * printf_srev - function that prints a str in reverse
 * @args: type struct va_arg where is allocated print
 * Return: the string
 */
int printf_srev(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		;

	for (i--; i >= 0; i--)
		count += _putchar(str[i]);

	return (count);
}
