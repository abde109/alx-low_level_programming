#include "main.h"

/**
 * print_buffer - Prints a buffer 10 bytes at a time, starting with
 *                the byte position, then showing the hex content,
 *                then displaying printable characters.
 * @b: The buffer to be printed.
 * @size: The number of bytes to be printed from the buffer.
 */
void print_buffer(char *b, int size)
{
	int byte, index;

	for (byte = 0; byte < size; byte += 10)
	{
		_putchar(byte / (16 * 16 * 16) % 16 + '0');
		_putchar(byte / (16 * 16) % 16 + '0');
		_putchar(byte / 16 % 16 + '0');
		_putchar(byte % 16 + '0');
		_putchar(':');
		_putchar(' ');

		for (index = 0; index < 10; index++)
		{
			if ((index + byte) >= size)
				_putchar(' ');

			else
			{
				_putchar(*(b + index + byte) / 16 + '0');
				_putchar(*(b + index + byte) % 16 + '0');
			}

			if ((index % 2) != 0 && index != 0)
				_putchar(' ');
		}

		for (index = 0; index < 10; index++)
		{
			if ((index + byte) >= size)
				break;

			else if (*(b + index + byte) >= 31 &&
				 *(b + index + byte) <= 126)
				_putchar(*(b + index + byte));

			else
				_putchar('.');
		}

		if (byte >= size)
			continue;

		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}

