#include "alist.h"
#include <stdlib.h>

alist_t *create_list(int max_size)
{
    alist_t *list = (alist_t *)malloc(sizeof(alist_t));
    list->array = (int *)malloc(max_size * sizeof(int));
    list->max_size = max_size;
    list->length = 0;
    return list;
}

void copy_list(int *src, int *dest, int length)
{
    for (int i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
}

void resize(alist_t *list, int factor)
{
    // get the new size of the list
    int new_size = list->max_size * factor;
    // initiate a new list
    int *new_list = (int *)malloc(new_size * sizeof(int));
    // copy the elements of a list from one to another, and delete the original list
    copy_list(list->array, new_list, list->max_size);
    free(list->array);
    // set the alist_t attribute
    list->array = new_list;
    list->max_size = new_size;
}

void insert_item(alist_t *list, int item, int index)
{
    if (full(list))
    {
        resize(list, 2);
    }
    int *head = list->array;
    for (int i = list->length; i > index; i--)
    {
        head[i] = head[i - 1];
    }
    head[index] = item;
    list->length += 1;
}

void delete_item(alist_t *list, int item)
{
    if (empty(list))
    {
        printf("The list is empty, nothing to delete");
        return;
    }
    int index = find(list, item);
    if (index == -1)
    {
        printf("The element does not exist.");
        return;
    }
    int *head = list->array;
    for (int i = index; i < list->length - 1; i++)
    {
        head[i] = head[i + 1];
    }
    list->length -= 1;
}

int find(alist_t *list, int item)
{
    int *head = list->array;
    for (int i = 0; i < list->length; i++)
    {
        if (head[i] == item)
        {
            return i;
        }
    }
    return -1;
}

void modify(alist_t *list, int old_item, int new_item)
{
    int index = find(list, old_item);
    if (index == -1)
    {
        printf("The element does not exist.");
        return;
    }
    list->array[index] = new_item;
}

void delete_list(alist_t *list)
{
    free(list->array);
    list->length = 0;
    list->max_size = 0;
    free(list);
}

void print_list(alist_t *list)
{
    int *head = list->array;
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", head[i]);
    }
    printf("\n");
}

bool full(alist_t *list)
{
    return list->length == list->max_size;
}

bool empty(alist_t *list)
{
    return list->length == 0;
}
