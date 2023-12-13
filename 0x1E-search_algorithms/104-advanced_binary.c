#include "search_algos.h"

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_binary - Recursively performs a binary search to find the first
 * occurrence of a value in an array.
 * @array: Pointer to the first element of the array to search in.
 * @left: Left index of the subarray to search.
 * @right: Right index of the subarray to search.
 * @value: Value to search for.
 * Return: The index where value is located.
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right >= left)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;

		if ((mid == left || array[mid - 1] < value) && array[mid] == value)
			return (mid);

		if (array[mid] >= value)
			return (recursive_binary(array, left, mid, value));

		return (recursive_binary(array, mid + 1, right, value));
	}

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 * Return: The first index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
