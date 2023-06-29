#include "main.h"
/**
 * printf_HEX - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_HEX(va_list val)
{
        int j;
        int *array;
        int counter = 0;

        unsigned int number = va_arg(val, unsigned int);
        unsigned int temper = number;

        while (number / 16 != 0)
        {
                number /= 16;
                counter++;
        }
        counter++;
        array = malloc( sizeof(int) * counter);

        for (j = 0; j < counter; j++)
        {
                array[j] = temper % 16;
                temper /= 16;
        }
        for (j = counter - 1; j >= 0; j--)
        {
                if (array[j] > 9)
                        array[j] = array[j] + 7;
                _putchar(array[j] + '0');
        }
        free(array);
        return (counter);
}
