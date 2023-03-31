#include "main.h"

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1, len2, len, carry, sum, idx1, idx2, idx_r;

    for (len1 = 0; n1[len1] != '\0'; len1++)
        ;
    for (len2 = 0; n2[len2] != '\0'; len2++)
        ;

    if (len1 > len2)
        len = len1;
    else
        len = len2;

    if (len + 1 >= size_r)
        return (0);

    r[len + 1] = '\0';

    carry = 0;
    idx1 = len1 - 1;
    idx2 = len2 - 1;
    idx_r = len;

    while (idx1 >= 0 || idx2 >= 0 || carry != 0)
    {
        sum = carry;
        if (idx1 >= 0)
            sum += n1[idx1] - '0';

        if (idx2 >= 0)
            sum += n2[idx2] - '0';

        carry = sum / 10;
        r[idx_r] = (sum % 10) + '0';

        idx1--;
        idx2--;
        idx_r--;
    }

    if (r[0] == '0')
    {
        return (r + 1);
    }
    else
    {
        return r;
    }
}

