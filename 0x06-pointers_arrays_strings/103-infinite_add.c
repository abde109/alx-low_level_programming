#include "main.h"
#include <stdio.h>

/**
 * is_printable - checks if a character is printable
 * @c: character to check
 *
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
    int i, j;

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
                printf("%02x", b[i + j]);
            else
                printf("  ");

            if (j % 2)
                printf(" ");
        }

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                if (is_printable(b[i + j]))
                    putchar(b[i + j]);
                else
                    putchar('.');
            }
        }

        putchar('\n');
    }

    if (size <= 0)
        putchar('\n');
}

