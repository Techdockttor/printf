#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: The number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[20];
	int count = 0, i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
		if (format[i] == 'c')
		count += custom_putchar(va_arg(args, int));

		else if (format[i] == 's')
		{
			char *s = va_arg(args, char *);

			s = s ? s : "(null)";
			count += custom_puts(s);
		}
		else if (format[i] == 'i' || format[i] == 'd')
		{
			snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
			count += custom_puts(buffer);
		}
		else if (format[i] == '%')
		count += custom_putchar('%');
		else
		{
			count += custom_putchar('%');
			count += custom_putchar(format[i]);
		}
		}
		else
		count += custom_putchar(format[i]);
		i++;
	}

	va_end(args);
	return (count);
}
