/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:41:30 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 14:36:50 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

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
	int size;

	printf("Test 1: Empty list\n");
	size = ft_lstsize(list);
	printf("Size: %d (Expected: 0)\n\n", size);

	printf("Test 2: Single node\n");
	n1 = ft_lstnew("Node1");
	list = n1;

	size = ft_lstsize(list);
	printf("Size: %d (Expected: 1)\n\n", size);

	printf("Test 3: Multiple nodes\n");
	n2 = ft_lstnew("Node2");
	n3 = ft_lstnew("Node3");

	n1->next = n2;
	n2->next = n3;

	size = ft_lstsize(list);
	printf("Size: %d (Expected: 3)\n\n", size);

	printf("Test 4: Verify list not modified\n");
	if (list == n1)
		printf("Head still points to Node1\n");
	else
		printf("Head modified!\n");

	printf("\nTest 5: Different data types\n");
	int num = 42;
	t_list *n4 = ft_lstnew(&num);

	n3->next = n4;

	size = ft_lstsize(list);
	printf("Size: %d (Expected: 4)\n\n", size);

	free_list(list);

	return (0);
}


/*


#include <stdio.h>
int main(void)
{
	t_list *node = NULL;
	char *s = "abcd";
	t_list *new = ft_lstnew(s);
	ft_lstadd_front(&node,ft_lstnew("welcome"));
	ft_lstadd_front(&node,ft_lstnew("arunima"));
	ft_lstadd_front(&node,ft_lstnew("2099"));
	//ft_lstadd_front(&node,ft_lstnew(98));
	printf("Size of linked list = %d", ft_lstsize(node));
	while(node)
	{
		printf("\nnode = %p\n", node);
		printf("content = %s\n", (char *)node->content);
		printf("next = %p\n", node->next);
		node = node->next;
	}
	
}

*/