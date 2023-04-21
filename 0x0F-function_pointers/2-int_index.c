#include "function_pointers.h"

/**
 * int_index - Searches for an integer.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * @cmp: Pointer to the function to be used to compare values.
 *
 * Return: The index of the first element for which the cmp function
 *         does not return 0. If no element matches or size <= 0,
 *         return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (array != NULL && cmp != NULL && size > 0)
    {
        for (i = 0; i < size; i++)
        {
            if (cmp(array[i]))
            {
                return (i);
            }
        }
    }
    return (-1);
}

