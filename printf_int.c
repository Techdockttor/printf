#include "main.h"

/**
 * check_int - handles %d and %i (integers)
 * @format: formatted string to print
 * Return: count
 */

int check_int(const char *format, ...)
{
	va_list args;
	int i;
	int value;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
			format++;

			if (*format == 'd' || *format == 'i')
			{
				count += custom_putchar("%d", va_arg(args, int));
			}
			else
			{
				custom_putchar('%');
				count++;
			}
		else
			custom_putchar(*format);
			count++;

		format++;
	}
	va_end(args);
	return (count);
}
