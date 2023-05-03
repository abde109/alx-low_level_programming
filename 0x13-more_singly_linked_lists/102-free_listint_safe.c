#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely.
 * @h: double pointer to the start of the list.
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
    size_t nodes = 0;
    listint_t *slow_ptr, *fast_ptr, *prev;

    if (h == NULL || *h == NULL)
        return (0);

    slow_ptr = *h;
    fast_ptr = *h;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        nodes++;

        if (slow_ptr == fast_ptr)
        {
            prev->next = NULL;
            break;
        }
    }

    while (*h != NULL)
    {
        prev = (*h);
        *h = (*h)->next;
        free(prev);
        nodes++;
    }

    *h = NULL;

    return (nodes);
}

