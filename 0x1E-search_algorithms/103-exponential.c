#include "search_algos.h"
#include <stdio.h>

int recursive_binary_search(int *array, size_t left, size_t right, int value);

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using an advanced form of binary search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}

/**
 * recursive_binary_search - Recursive helper function for advanced binary.
 * @array: Pointer to the first element of the array.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 * @value: Value to search for.
 *
 * Return: The first index where value is located.
 */
int recursive_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	size_t i;

	if (left == right)
		return (array[left] == value ? (int)left : -1);

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	mid = left + (right - left) / 2;

	if (array[mid] < value)
		return (recursive_binary_search(array, mid + 1, right, value));
	else
		return (recursive_binary_search(array, left, mid, value));
}
