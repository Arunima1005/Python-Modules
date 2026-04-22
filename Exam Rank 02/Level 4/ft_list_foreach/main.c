#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
// Function to apply to each element
void    print_data(void *data)
{
    printf("%s\n", (char *)data);
}

// Helper to create a new node
t_list  *create_node(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *head = create_node("Hello");
    head->next = create_node("World");
    head->next->next = create_node("42");

    ft_list_foreach(head, print_data);

    // Free memory
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}