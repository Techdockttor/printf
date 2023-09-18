#include "main.h"

/**
 * custom_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * custom_puts - prints a string to stdout
 * @s: A string to print
 * Return: The length of the string
 */
int custom_puts(char *s)
{
	int z = 0;

	while (s[z])
	{
		custom_putchar(s[z]);
		z++;
	}
	return (z);
}
