/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:16:48 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 17:23:05 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>


void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *list = NULL;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	printf("------ Edge Case 1: lst == NULL ------\n");
	node1 = ft_lstnew(&a);
	ft_lstadd_back(NULL, node1);

	printf("------ Edge Case 2: new == NULL ------\n");
	ft_lstadd_back(&list, NULL);

	printf("------ Edge Case 3: Empty list ------\n");
	node1 = ft_lstnew(&a);
	ft_lstadd_back(&list, node1);
	print_list(list);

	printf("------ Edge Case 4: Add second node ------\n");
	node2 = ft_lstnew(&b);
	ft_lstadd_back(&list, node2);
	print_list(list);

	printf("------ Edge Case 5: Add third node ------\n");
	node3 = ft_lstnew(&c);
	ft_lstadd_back(&list, node3);
	print_list(list);

	printf("------ Edge Case 6: Add multiple nodes ------\n");
	ft_lstadd_back(&list, ft_lstnew(&d));
	ft_lstadd_back(&list, ft_lstnew(&e));
	print_list(list);

	return (0);
}

/*

| Case          | Reason                        |
| ------------- | ----------------------------- |
| `lst == NULL` | Prevents segmentation fault   |
| `new == NULL` | Should safely ignore          |
| empty list    | Must correctly set first node |
| normal list   | Must traverse to last node    |
| multiple adds | Ensures chaining works        |

------ Edge Case 1: lst == NULL ------
------ Edge Case 2: new == NULL ------
------ Edge Case 3: Empty list ------
10 -> NULL
------ Edge Case 4: Add second node ------
10 -> 20 -> NULL
------ Edge Case 5: Add third node ------
10 -> 20 -> 30 -> NULL
------ Edge Case 6: Add multiple nodes ------
10 -> 20 -> 30 -> 40 -> 50 -> NULL

*/