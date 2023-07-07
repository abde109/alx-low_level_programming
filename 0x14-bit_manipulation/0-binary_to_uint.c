#include "main.h"

unsigned int binary_to_uint(const char *b)
{
    unsigned int num = 0;

    if (!b)
        return (0);

    while (*b)
    {
        num <<= 1;
        if (*b == '1')
            num |= 1;
        else if (*b != '0')
            return (0);
        b++;
    }

    return (num);
}

