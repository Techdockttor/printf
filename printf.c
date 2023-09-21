#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: Character string that directs the format of the output
 * Return: number of characters printed
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[20];
	int count = 0, z = 0;

	va_start(args, format);
	while (format[z])
	{
		if (format[z] == '%' && format[z + 1])
		{
			z++;
		if (format[z] == 'c')
		count += custom_putchar(va_arg(args, int));

		else if (format[z] == 's')
		{
			char *s = va_arg(args, char *);

			if (s == NULL)
				s = "(null)";

			count += custom_puts(s);
		}
		else if (format[z] == 'i' || format[z] == 'd')
		{
			snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));
			count += custom_puts(buffer);
		}
		else if (format[z] == '%')
		count += custom_putchar('%');
		else
		{
			count += custom_putchar('%');
			count += custom_putchar(format[z]);
		}
		}
		else
		count += custom_putchar(format[z]);
		z++;
	}

	va_end(args);
	return (count);
}
