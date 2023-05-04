#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - print a listint_t list safely
 * @head: pointer to the start of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head, *start = head;
    size_t nodes = 0;
    int loop_found = 0;

    if (head == NULL)
        return (0);

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loop_found = 1;
            break;
        }
    }

    if (loop_found)
    {
        /* Reset slow pointer */
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        start = slow;
    }

    slow = head;

    while (slow != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        nodes++;

        if (slow == start && loop_found)
        {
            printf("-> [%p] %d\n", (void *)slow, slow->n);
            break;
        }

        slow = slow->next;
    }

    return (nodes);
}

