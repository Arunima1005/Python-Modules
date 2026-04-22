#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
// Function to compare two strings
int cmp(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

// Function to print list
void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// Helper to create node
t_list *create_node(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// Add node to front (simple helper)
void push_front(t_list **list, void *data)
{
    t_list *new = create_node(data);
    new->next = *list;
    *list = new;
}

// Free whole list
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

    // Build list: "42" -> "world" -> "42" -> "hello"
    push_front(&list, "hello");
    push_front(&list, "42");
	push_front(&list, "42");
    push_front(&list, "world");
    push_front(&list, "42");
	push_front(&list, "42");
	push_front(&list, "42");

    printf("Before:\n");
    print_list(list);

    // Remove all "42"
    ft_list_remove_if(&list, "42", cmp);

    printf("\nAfter removing \"42\":\n");
    print_list(list);

    free_list(list);
    return 0;
}
