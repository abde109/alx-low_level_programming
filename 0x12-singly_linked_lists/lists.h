/* File: lists.h */

#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <string.h>

/* Structure for list_t */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/* Other function prototypes... */

/* Prototype for print_list */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);

#endif /* LISTS_H */

