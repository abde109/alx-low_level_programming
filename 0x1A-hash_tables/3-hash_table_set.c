#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *temp;

    if (!ht || !key || !value || strlen(key) == 0)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    /* Check for collision */
    temp = ht->array[index];
    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            return (1);
        }
        temp = temp->next;
    }

    /* Create a new node */
    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);

    /* Handle insertion at the beginning in case of collision */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
