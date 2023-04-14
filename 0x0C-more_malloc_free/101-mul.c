#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(char c)
{
    return c >= '0' && c <= '9';
}

/**
 * error_exit - prints "Error" and exits with code 98
 */
void error_exit(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    unsigned long num1, num2;
    char *ptr;

    if (argc != 3)
        error_exit();

    for (ptr = argv[1]; *ptr; ++ptr)
        if (!_isdigit(*ptr))
            error_exit();

    for (ptr = argv[2]; *ptr; ++ptr)
        if (!_isdigit(*ptr))
            error_exit();

    num1 = strtoul(argv[1], NULL, 10);
    num2 = strtoul(argv[2], NULL, 10);
    printf("%lu\n", num1 * num2);

    return (0);
}

