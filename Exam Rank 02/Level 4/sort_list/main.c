#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
// cmp function: ascending order
int ascending(int a, int b)
{
    return (a <= b);
}

// create new node
t_list *create_node(int data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// add node to front
void push_front(t_list **list, int data)
{
    t_list *new = create_node(data);
    new->next = *list;
    *list = new;
}

// print list
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// free list
void free_list(t_list *list)
{
    t_list *tmp;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main(void)
{
    t_list *list = NULL;

    // Build list: 4 -> 2 -> 5 -> 1 -> 3
    push_front(&list, 3);
    push_front(&list, 1);
    push_front(&list, 5);
    push_front(&list, 2);
    push_front(&list, 4);

    printf("Before:\n");
    print_list(list);

    list = sort_list(list, ascending);

    printf("\nAfter sorting:\n");
    print_list(list);

    free_list(list);
    return 0;
}