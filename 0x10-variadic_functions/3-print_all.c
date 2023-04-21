#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function.
 * ...: The variable-length list of parameters.
 *
 * Allowed types:
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 *
 * Any other char will be ignored.
 * Prints a new line at the end of the function.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *sep = "";
    char *str;

    va_start(args, format);
    while (format != NULL && format[i] != '\0')
    {
        switch (format[i])
        {
        case 'c':
            printf("%s%c", sep, va_arg(args, int));
            break;
        case 'i':
            printf("%s%d", sep, va_arg(args, int));
            break;
        case 'f':
            printf("%s%f", sep, va_arg(args, double));
            break;
        case 's':
            str = va_arg(args, char *);
            if (str == NULL)
                str = "(nil)";
            printf("%s%s", sep, str);
            break;
        default:
            i++;
            continue;
        }
        sep = ", ";
        i++;
    }
    va_end(args);
    printf("\n");
}

