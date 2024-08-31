#include "llist.h"
#include <cstddef>

llist *init_list()
{
    llist *list = (llist *)malloc(sizeof(llist));
    list->first = (node_t *)malloc(sizeof(node_t));
    list->first->next = NULL;
    list->length = 0;
    return list;
}

bool empty(llist *list)
{
    return list->length == 0;
}

bool is_last_note(node_t *node)
{
    return node->next == NULL;
}

int find(llist *list, int val)
{
    node_t *p = list->first->next;
    while (p != NULL)
    {
        if (p->val == val)
        {
            return val;
        }
        p = p->next;
    }
    return -1;
}

void insert(llist *list, int index, int val)
{
    node_t *p = list->first;
    while (p->next != NULL && index > 1)
    {
        p = p->next;
        index -= 1;
    }
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node;
    list->length += 1;
}

void delete(llist *list, int val)
{
    node_t *p = list->first;
    while (p->next != NULL)
    {
        if (p->next->val == val)
        {
            node_t *q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}

void delete_list(llist *list)
{
    node_t *previous = NULL;
    node_t *current = list->first;
    while (current != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    free(list);
}

node_t *get_head(llist *list)
{
    return list->first;
}

node_t *get_first(llist *list)
{
    return list->first->next;
}
