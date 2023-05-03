#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - a function that frees a listint_t list and sets the head to NULL.
 * @head: double pointer to the start of the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    if (head == NULL)
    {
        return;
    }

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL; 
}

