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
        print_hex(o);
        for (i = 0; i < 10; i++)
        {
            if (i < j)
            {
                print_hex(*(b + o + i));
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

void print_hex(int num)
{
    int i;
    char hex[9];
    for (i = 7; i >= 0; i--)
    {
        hex[i] = "0123456789abcdef"[num % 16];
        num /= 16;
    }
    hex[8] = '\0';
    for (i = 0; i < 8; i++)
    {
        _putchar(hex[i]);
    }
    _putchar(':');
    _putchar(' ');
}

