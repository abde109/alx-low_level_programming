#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: pointer to the head of the list
 *
 * Return: void
 */
void free_list(listp_t **head)
{
    listp_t *temp;
    listp_t *current;

    if (head != NULL)
    {
        current = *head;
        while ((temp = current) != NULL)
        {
            current = current->next;
            free(temp);
        }
        *head = NULL;
    }
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t node_count = 0;
    listp_t *visited_nodes, *new_node, *iterator;

    visited_nodes = NULL;
    while (head != NULL)
    {
        new_node = malloc(sizeof(listp_t));

        if (new_node == NULL)
            exit(98);

        new_node->p = (void *)head;
        new_node->next = visited_nodes;
        visited_nodes = new_node;

        iterator = visited_nodes;

        while (iterator->next != NULL)
        {
            iterator = iterator->next;
            if (head == iterator->p)
            {
                printf("-> [%p] %d\n", (void *)head, head->n);
                free_list(&visited_nodes);
                return (node_count);
            }
        }

        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
        node_count++;
    }

    free_list(&visited_nodes);
    return (node_count);
}

