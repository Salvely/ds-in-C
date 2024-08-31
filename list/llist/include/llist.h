#include <stdbool.h>

typedef struct node
{
    int val;
    node_t *next;
} node_t;

typedef struct llist
{
    node_t *first;
    int length;
} llist;

llist *init_list();

bool empty(llist *list);

bool is_last_note(node_t *node);

int find(llist *list, int val);

void delete(llist *list, int val);

void insert(llist *list, int index, int val);

void delete_list(llist *list);

node_t *get_head(llist *list);

node_t *get_first(llist *list);