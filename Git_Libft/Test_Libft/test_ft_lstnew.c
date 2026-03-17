/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:12:48 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 11:21:27 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	print_node(t_list *node)
{
	if (!node)
	{
		printf("Node is NULL\n");
		return;
	}
	printf("Node address: %p\n", node);
	printf("Content pointer: %p\n", node->content);
	printf("Next pointer: %p\n", node->next);
}

int	main(void)
{
	printf("===== Test 1: Normal string content =====\n");
	char *str = "Hello 42";
	t_list *node1 = ft_lstnew(str);
	print_node(node1);
	if (node1 && node1->content)
		printf("Content: %s\n", (char *)node1->content);
	free(node1);

	printf("\n===== Test 2: NULL content =====\n");
	t_list *node2 = ft_lstnew(NULL);
	print_node(node2);
	if (node2->content == NULL)
		printf("Content is NULL as expected\n");
	free(node2);

	printf("\n===== Test 3: Integer content =====\n");
	int num = 42;
	t_list *node3 = ft_lstnew(&num);
	print_node(node3);
	if (node3 && node3->content)
		printf("Content value: %d\n", *(int *)node3->content);
	free(node3);

	printf("\n===== Test 4: Large content =====\n");
	char *large = malloc(1000);
	strcpy(large, "Large test content");
	t_list *node4 = ft_lstnew(large);
	print_node(node4);
	if (node4 && node4->content)
		printf("Content: %s\n", (char *)node4->content);
	free(large);
	free(node4);

	// printf("\n===== Test 5: Multiple nodes =====\n");
	// t_list *n1 = ft_lstnew("First");
	// t_list *n2 = ft_lstnew("Second");
	// t_list *n3 = ft_lstnew("Third");

	// n1->next = n2;
	// n2->next = n3;

	// t_list *tmp = n1;
	// while (tmp)
	// {
	// 	printf("Node content: %s\n", (char *)tmp->content);
	// 	tmp = tmp->next;
	// }

	// free(n1);
	// free(n2);
	// free(n3);

	// printf("\n===== Test 6: Check next initialization =====\n");
	// t_list *node6 = ft_lstnew("Check next");
	// if (node6->next == NULL)
	// 	printf("PASS: next is initialized to NULL\n");
	// else
	// 	printf("FAIL: next is not NULL\n");
	// free(node6);

	return (0);
}

/*
| Test             | What it verifies             |
| ---------------- | ---------------------------- |
| String content   | Standard case                |
| NULL content     | Allowed by subject           |
| Integer pointer  | Generic `void *` support     |
| Large allocation | Memory handling              |
| Multiple nodes   | Works in linked list context |
| `next == NULL`   | Correct initialization       |


*/