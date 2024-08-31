#include "alist.h"
int main(void)
{
    alist_t *list = create_list(10);
    print_list(list);

    for (int i = 0; i < 10; i++)
    {
        insert_item(list, i, i);
    }
    print_list(list);

    for (int i = 0; i < 10; i++)
    {
        insert_item(list, i, i);
    }
    print_list(list);

    delete_item(list, 1);
    print_list(list);

    for (int i = 0; i < list->length; i++)
    {
        modify(list, i, 10 + i);
    }
    print_list(list);
    delete_list(list);
}