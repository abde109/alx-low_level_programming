#include "lists.h"
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the list.
 * @str: String to be included in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node;
    list_t *last = *head;
    size_t len = 0;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return NULL;
    }

    while (str[len])
        len++;

    new_node->len = len;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return new_node;
    }

    while (last->next)
        last = last->next;

    last->next = new_node;

    return new_node;
}

