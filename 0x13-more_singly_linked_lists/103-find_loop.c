#include "lists.h"

/**
 * find_listint_loop - Finds the start of a loop in a linked list
 * @head: The head of the linked list
 *
 * Return: The address of the start of the loop, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow_ptr = head, *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if (slow_ptr == fast_ptr)
        {
            slow_ptr = head;
            while (slow_ptr != fast_ptr)
            {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            return slow_ptr;
        }
    }
    return NULL;
}

