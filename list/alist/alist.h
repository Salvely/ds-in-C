#include <stdio.h>
#include <stdbool.h>

typedef struct alist
{
    int *array;
    int max_size;
    int length;
} alist_t;

alist_t *create_list(int max_size);

void resize(alist_t *list, int factor);

void copy_list(int *src, int *dest, int length);

/**
 * @brief insert the item in index position
 *
 * @param list the list to be inserted
 * @param item the item to be inserted
 * @param index the index of the position, starting from 0
 */
void insert_item(alist_t *list, int item, int index);

void delete_item(alist_t *list, int item);

int find(alist_t *list, int item);

void modify(alist_t *list, int old_item, int new_item);

void delete_list(alist_t *list);

void print_list(alist_t *list);

bool full(alist_t *list);

bool empty(alist_t *list);
