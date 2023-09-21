#include <stdio.h>
#include <stdarg.h>

/**
 * _shaprintf - Formats and prints data to a string
 * @str: The string buffer to write to
 * @format: The format string
 * @...: Optional arguments to format
 *
 * Return: The number of characters written to the buffer, excluding the null
 * byte, or -1 if an unsupported conversion specifier was encountered
 */
int _shaprintf(char *str, const char *format, ...)
{
	va_list args;
	int num, written = 0, z = 0;
	char *s;

	if (str == NULL)
		return (-1);
	if (format == NULL)
	{
		str[0] = '\0';
		return (0);
	}
	va_start(args, format);
	while (format[z])
	{
		if (format[z] == '%')
		{
			z++;
			switch (format[z])
			{
				case 'd':
				case 'i':
					num = va_arg(args, int);
					written += snprintf(str + written, 128, "%d", num);

				break;
				case 's':
					s = va_arg(args, char *);
					written += snprintf(str + written, 128, "%s", s);
				break;
				default:

				return (-1);
			}
		}
else
			str[written++] = format[z];
		z++;	}
	str[written] = '\0';
	va_end(args);
	return (written);
}
