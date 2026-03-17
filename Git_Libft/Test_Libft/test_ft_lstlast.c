/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:49:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 16:16:07 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
	t_list *last;

	printf("Test 1: Empty list\n");
	last = ft_lstlast(list);
	if (!last)
		printf("Returned NULL (Expected)\n\n");

	printf("Test 2: Single node list\n");
	t_list *n1 = ft_lstnew("Node1");
	list = n1;

	last = ft_lstlast(list);
	printf("Last node content: %s (Expected: Node1)\n\n", (char *)last->content);

	printf("Test 3: Multiple nodes\n");
	t_list *n2 = ft_lstnew("Node2");
	t_list *n3 = ft_lstnew("Node3");

	n1->next = n2;
	n2->next = n3;

	last = ft_lstlast(list);
	printf("Last node content: %s (Expected: Node3)\n\n", (char *)last->content);

	printf("Test 4: Verify returned node is actually last\n");
	if (last == n3)
		printf("Correct last node returned\n\n");

	printf("Test 5: Different data type content\n");
	int num = 42;
	t_list *n4 = ft_lstnew(&num);
	n3->next = n4;

	last = ft_lstlast(list);
	printf("Last node integer: %d (Expected: 42)\n\n", *(int *)last->content);

	// printf("Test 6: Ensure original list head unchanged\n");
	// if (list == n1)
	// 	printf("Head still points to Node1\n");

	free_list(list);
	return (0);
}
/*


Test 1: Empty list
Returned NULL (Expected)

Test 2: Single node list
Last node content: Node1 (Expected: Node1)

Test 3: Multiple nodes
Last node content: Node3 (Expected: Node3)

Test 4: Verify returned node is actually last
Correct last node returned

Test 5: Different data type content
Last node integer: 42 (Expected: 42)


*/
