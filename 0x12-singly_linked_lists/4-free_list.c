#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the list.
 *
 */
void free_list(list_t *head)
{
    list_t *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->str);
        free(tmp);
    }
}

