#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_list(args, format);

	while (*format)
	{
		if (*format == '%')
			format++;

			if (*format == 'c')
			{
				char c = va_args(args, int);

				custom_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_args(args, char *);

				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					custom_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
				custom_putchar('%');
				count++;
			else
				custom_puchar('%');
				count++;
				custom_putchar(*format);
				count++;
		else
			custom_putchar(*format);
			count++;
		format++;
	}
	va_end(args);

	return (count);
}
