#include "lists.h"

/**
 * listint_len - a function that returns the number of elements in a listint_t list.
 * @h: pointer to the start of the list.
 *
 * Return: the number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
    size_t nodes = 0;

    while (h)
    {
        nodes++;
        h = h->next;
    }
    return nodes;
}

