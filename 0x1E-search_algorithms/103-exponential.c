#include "search_algos.h"

/**
 * binary_search_subarray - Performs binary search on a subarray
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: Value to search for
 * Return: Index where value is located, or -1
 */
int binary_search_subarray(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	size_t i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");

		if (array[mid] == value)
			return ((int)mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, or -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	bound = (bound < size ? bound : size - 1);
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound);
	return (binary_search_subarray(array, bound / 2, bound, value));
}

