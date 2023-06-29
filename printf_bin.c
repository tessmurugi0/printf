#include "main.h"
/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
int printf_bin(va_list val)
{
	int flag = 0;
	int count = 0;
	int J, K = 1, b;

	unsigned int number = va_arg(val, unsigned int);
	unsigned int p;

	for (J = 0; J < 32; J++)
	{
		p = ((K << (31 - J)) & number);
		if (p >> (31 - J))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - J);
			_putchar(b + 48);
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}
