#include "hash_tables.h"
#include <string.h>

char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *temp;

    if (!ht || !key || strlen(key) == 0)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
            return (temp->value);
        temp = temp->next;
    }

    return (NULL);
}
