/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:00:52 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 20:11:27 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/* Function to print content */
void	print_content(void *content)
{
	printf("%s ", (char *)content);
}

/* Function to modify content */
void	to_uppercase(void *content)
{
	char *str = (char *)content;
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

/* Helper function to print full list */
void	print_list(t_list *lst)
{
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

	t_list *head = ft_lstnew(strdup("hello"));
	head->next = ft_lstnew(strdup("world"));
	head->next->next = ft_lstnew(strdup("libft"));

	print_list(head);

	printf("Applying print_content:\n");
	ft_lstiter(head, print_content);
	printf("\n");


	printf("\n===== TEST 2: Modify content =====\n");

	ft_lstiter(head, to_uppercase);

	print_list(head);


	printf("\n===== TEST 3: Single node =====\n");

	t_list *single = ft_lstnew(strdup("single"));

	ft_lstiter(single, print_content);
	printf("\n");


	printf("\n===== TEST 4: Empty list =====\n");

	t_list *empty = NULL;

	ft_lstiter(empty, print_content);

	printf("Handled NULL list safely\n");


	printf("\n===== TEST 5: NULL function =====\n");

	ft_lstiter(head, NULL);

	printf("Handled NULL function safely\n");


	/* Cleanup memory */
	t_list *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}

	free(single->content);
	free(single);

	printf("\n===== ALL TESTS FINISHED =====\n");

	return (0);
}
/*

| Case                      | Why                               |
| ------------------------- | --------------------------------- |
| `lst == NULL`             | Should not crash                  |
| `f == NULL`               | Should safely return              |
| Single node               | Basic functionality               |
| Multiple nodes            | Normal use                        |
| Function modifies content | Confirms `f` is applied correctly |


===== TEST 1: Normal list =====
hello -> world -> libft -> NULL
Applying print_content:
hello world libft 

===== TEST 2: Modify content =====
HELLO -> WORLD -> LIBFT -> NULL

===== TEST 3: Single node =====
single 

===== TEST 4: Empty list =====
Handled NULL list safely

===== TEST 5: NULL function =====
Handled NULL function safely

===== ALL TESTS FINISHED =====

*/