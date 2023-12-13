#include "search_algos.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer on the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list, *express;

	if (!list)
		return (NULL);

	while (node->express && node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
	node->express->index, node->express->n);

		node = node->express;
	}

	express = node->express ? node->express : node;
	while (express->next)
		express = express->next;

	printf("Value found between indexes [%lu] and [%lu]\n",
	   node->index, node->express ? node->express->index : 0);


	while (node && node->n < value)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
	   node->index, node->express ? node->express->index : 0);



		node = node->next;
	}

	if (node && node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
	   node->express->index, node->express->n);


		return (node);
	}

	return (NULL);
}
