/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:22:37 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 12:28:23 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s -> ", (char *)head->content);
		head = head->next;
	}
	printf("NULL\n");
}

void	free_list(t_list *head)
{
	t_list *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int	main(void)
{
	t_list *list = NULL;
	t_list *n1;
	t_list *n2;
	t_list *n3;

	printf("Test 1: Add node to empty list\n");
	n1 = ft_lstnew("Node1");
	ft_lstadd_front(&list, n1);
	print_list(list);

	printf("\nTest 2: Add another node to front\n");
	n2 = ft_lstnew("Node2");
	ft_lstadd_front(&list, n2);
	print_list(list);

	printf("\nTest 3: Add third node to front\n");
	n3 = ft_lstnew("Node3");
	ft_lstadd_front(&list, n3);
	print_list(list);

	printf("\nTest 4: new == NULL\n");
	ft_lstadd_front(&list, NULL);
	print_list(list);

	printf("\nTest 5: lst == NULL\n");
	ft_lstadd_front(NULL, n1);
	printf("No crash (handled correctly)\n");

	printf("\nTest 6: Verify list order\n");
	t_list *tmp = list;
	while (tmp)
	{
		printf("Node content: %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	free_list(list);
	return (0);
}

/*

| Test | Case                  |
| ---- | --------------------- |
| 1    | Add to empty list     |
| 2    | Add to non-empty list |
| 3    | Multiple insertions   |
| 4    | `new == NULL`         |
| 5    | `lst == NULL`         |
| 6    | Order verification    |


Test 1: Add node to empty list
Node1 -> NULL

Test 2: Add another node to front
Node2 -> Node1 -> NULL

Test 3: Add third node to front
Node3 -> Node2 -> Node1 -> NULL

Test 4: new == NULL
Node3 -> Node2 -> Node1 -> NULL

Test 5: lst == NULL
No crash (handled correctly)

Test 6: Verify list order
Node content: Node3
Node content: Node2
Node content: Node1

*/