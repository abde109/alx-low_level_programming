#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array, using malloc
 * @nmemb: Number of elements
 * @size: Size of each element
 * Return: Pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *alloc_mem;
    unsigned int total_size, i;

    if (nmemb == 0 || size == 0)
        return NULL;

    total_size = nmemb * size;
    alloc_mem = malloc(total_size);

    if (alloc_mem == NULL)
        return NULL;

    for (i = 0; i < total_size; i++)
        alloc_mem[i] = 0;

    return alloc_mem;
}

