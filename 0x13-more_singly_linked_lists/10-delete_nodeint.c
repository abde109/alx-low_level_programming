#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at a given index.
 * @head: double pointer to the start of the list.
 * @index: index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *temp2;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    temp = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(temp);
        return (1);
    }

    while (temp != NULL)
    {
        if (i == index - 1)
        {
            temp2 = temp->next;
            if (temp2 != NULL)
            {
                temp->next = temp2->next;
                free(temp2);
                return (1);
            }
            else
                return (-1);
        }
        temp = temp->next;
        i++;
    }

    return (-1);
}

