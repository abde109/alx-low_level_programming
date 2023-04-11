#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: 0 if successful, 1 if an error occurs
 */
int main(int argc, char *argv[])
{
    int a, b, result;

    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    result = a * b;

    printf("%d\n", result);

    return (0);
}

