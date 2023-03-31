#include "main.h"

/**
 * print_buffer - prints buffer
 * @b: buffer
 * @size: size
 * Return: void
 */

void print_buffer(char *b, int size)
{
    int o, j, i;

    o = 0;

    if (size <= 0)
    {
        _putchar('\n');
        return;
    }
    while (o < size)
    {
        j = size - o < 10 ? size - o : 10;
        _putchar(o / (16 * 16 * 16) % 16 + '0');
        _putchar(o / (16 * 16) % 16 + '0');
        _putchar(o / 16 % 16 + '0');
        _putchar(o % 16 + '0');
        _putchar(':');
        _putchar(' ');

        for (i = 0; i < 10; i++)
        {
            if (i < j)
            {
                _putchar(*(b + o + i) / 16 + '0');
                _putchar(*(b + o + i) % 16 + '0');
            }
            else
            {
                _putchar(' ');
                _putchar(' ');
            }
            if (i % 2)
            {
                _putchar(' ');
            }
        }
        for (i = 0; i < j; i++)
        {
            int c = *(b + o + i);

            if (c < 32 || c > 126)
            {
                c = '.';
            }
            _putchar(c);
        }
        _putchar('\n');
        o += 10;
    }
}

