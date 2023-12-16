#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using
 * the Jump search algorithm.
 * @list: Pointer to the head of the list.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: A pointer to the first node where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t idx = 0;
	size_t i;
	listint_t *prev = list, *current = list;

	if (!list)
		return (NULL);

	while (current->next != NULL && current->n < value)
	{
		prev = current;
		for (i = 0; i < jump && current->next != NULL; i++)
			current = current->next;
		idx = current->index;
		printf("Value checked at index [%lu] = [%d]\n", idx, current->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev->index, idx);

	for (; prev != NULL && prev->index <= idx; prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
