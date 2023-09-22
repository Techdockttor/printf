#include "main.h"
#include <stdio.h>

/**
 * convert_to_binary - converts an unsigned int to a binary string
 * @num: unsigned integer to convert
 * @binary: buffer to store the binary string 
 * Return: The binary string representation of num
 */

char *convert_to_binary(unsigned int num, char *binary)
	{
		int z;

		for (z = 0; z < 32; z++)

			binary[z] = (num & (1 << (31 - z))) ? '1' : '0';

		binary[z] = '\0';
		return (binary);
	}
