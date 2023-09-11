#include "hash_tables.h"
#include <stdlib.h>

void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *temp, *next;

    if (!ht)
        return;

    for (i = 0; i < ht->size; i++)
    {
        temp = ht->array[i];
        while (temp)
        {
            next = temp->next;
            free(temp->key);
            free(temp->value);
            free(temp);
            temp = next;
        }
    }

    free(ht->array);
    free(ht);
}
