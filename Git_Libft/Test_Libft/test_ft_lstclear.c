/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:36:40 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 19:49:38 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	del_content(void *content)
{
	printf("Deleting: %s\n", (char *)content);
	free(content);
}

/* Helper function to print list */
void	print_list(t_list *lst)
{
	printf("List: ");
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	printf("===== TEST 1: Normal list =====\n");

	t_list *head = ft_lstnew(strdup("one"));
	head->next = ft_lstnew(strdup("two"));
	head->next->next = ft_lstnew(strdup("three"));

	print_list(head);

	ft_lstclear(&head, del_content);

	if (head == NULL)
		printf("List cleared successfully\n");


	printf("\n===== TEST 2: Single node =====\n");

	t_list *single = ft_lstnew(strdup("single"));

	print_list(single);

	ft_lstclear(&single, del_content);

	if (single == NULL)
		printf("Single node cleared\n");


	printf("\n===== TEST 3: Empty list =====\n");

	t_list *empty = NULL;

	ft_lstclear(&empty, del_content);

	printf("Handled empty list safely\n");


	printf("\n===== TEST 4: NULL lst pointer =====\n");

	ft_lstclear(NULL, del_content);

	printf("Handled NULL lst pointer safely\n");


	printf("\n===== TEST 5: NULL del function =====\n");

	t_list *test = ft_lstnew(strdup("test"));

	ft_lstclear(&test, NULL);

	printf("Handled NULL del function\n");

	/* cleanup manually because del wasn't called */
	free(test->content);
	free(test);


	printf("\n===== ALL TESTS FINISHED =====\n");

	return (0);
}

/*

| Case                 | Why Important            |
| -------------------- | ------------------------ |
| `lst == NULL`        | Avoid segmentation fault |
| `*lst == NULL`       | Empty list               |
| `del == NULL`        | Must safely return       |
| Single node          | Common case              |
| Multiple nodes       | Core functionality       |
| Ensure `*lst = NULL` | Required by subject      |

===== TEST 1: Normal list =====
List: one -> two -> three -> NULL
Deleting: one
Deleting: two
Deleting: three
List cleared successfully

===== TEST 2: Single node =====
List: single -> NULL
Deleting: single
Single node cleared

===== TEST 3: Empty list =====
Handled empty list safely

===== TEST 4: NULL lst pointer =====
Handled NULL lst pointer safely

===== TEST 5: NULL del function =====
Handled NULL del function

===== ALL TESTS FINISHED =====

*/