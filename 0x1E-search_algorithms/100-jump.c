#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t jump = sqrt(size), prev = 0, i;

	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += jump;
	}

	if (prev < size)
		printf("Value found between indexes [%lu] and [%lu]\n", prev - jump, prev);

	for (i = prev - jump; i < size && i <= prev && array[i] <= value; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}
