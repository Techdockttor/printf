#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{

	va_list args;
	int count = 0, z = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	while (format[z])
	{
		if (format[z] == '%')
		{
			z++;
			handle_format(format + z, args, &count);
			while (format[z] && format[z] != '%' && !strchr("csiduoxX", format[z]))
			{
				count += custom_putchar(format[z]);
				z++;
			}
		}
		else
		{
			count += custom_putchar(format[z]);
			z++;
		}
	}

	va_end(args);
	return (count);
}
