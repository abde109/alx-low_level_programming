#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes of s2 to concatenate
 * Return: Pointer to newly allocated space in memory containing concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len_s1, len_s2, i;
    char *concat_str;

    if (s1 == NULL)
        s1 = "";

    if (s2 == NULL)
        s2 = "";

    len_s1 = strlen(s1);
    len_s2 = strlen(s2);

    if (n >= len_s2)
        n = len_s2;

    concat_str = malloc((len_s1 + n + 1) * sizeof(char));
    if (concat_str == NULL)
        return NULL;

    for (i = 0; i < len_s1; i++)
        concat_str[i] = s1[i];

    for (i = 0; i < n; i++)
        concat_str[len_s1 + i] = s2[i];

    concat_str[len_s1 + n] = '\0';

    return concat_str;
}

