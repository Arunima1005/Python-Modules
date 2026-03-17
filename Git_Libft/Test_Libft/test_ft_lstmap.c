/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:15:54 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 20:41:29 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/* delete function */
void	del_content(void *content)
{
	free(content);
}

/* function applied to each content */
void	*duplicate_upper(void *content)
{
	char	*str = (char *)content;
	char	*new;
	int		i;

	new = strdup(str);
	if (!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
		i++;
	}
	return (new);
}

/* helper to print list */
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

	printf("Original list:\n");
	print_list(head);

	t_list *new_list = ft_lstmap(head, duplicate_upper, del_content);

	printf("Mapped list:\n");
	print_list(new_list);

	printf("Original list should remain unchanged:\n");
	print_list(head);


	printf("\n===== TEST 2: Single node =====\n");

	t_list *single = ft_lstnew(strdup("single"));

	t_list *mapped_single = ft_lstmap(single, duplicate_upper, del_content);

	print_list(mapped_single);


	printf("\n===== TEST 3: Empty list =====\n");

	t_list *empty = NULL;

	t_list *mapped_empty = ft_lstmap(empty, duplicate_upper, del_content);

	if (!mapped_empty)
		printf("Handled NULL list correctly\n");


	printf("\n===== TEST 4: NULL function =====\n");

	t_list *null_test = ft_lstmap(head, NULL, del_content);

	if (!null_test)
		printf("Handled NULL function correctly\n");


	// printf("\n===== TEST 5: NULL del function (not recommended but safe here)\n");

	// t_list *mapped_no_del = ft_lstmap(head, duplicate_upper, NULL);

	// print_list(mapped_no_del);

	printf("\n===== TEST 5: Valid del function =====\n");

t_list *mapped_no_del = ft_lstmap(head, duplicate_upper, del_content);

print_list(mapped_no_del);


	/* Cleanup all lists */

	ft_lstclear(&head, del_content);
	ft_lstclear(&new_list, del_content);
	ft_lstclear(&single, del_content);
	ft_lstclear(&mapped_single, del_content);
	ft_lstclear(&mapped_no_del, del_content);

	printf("\n===== ALL TESTS COMPLETED =====\n");

	return (0);
}

/*
===== TEST 1: Normal list =====
Original list:
hello -> world -> libft -> NULL
Mapped list:
HELLO -> WORLD -> LIBFT -> NULL
Original list should remain unchanged:
hello -> world -> libft -> NULL

===== TEST 2: Single node =====
SINGLE -> NULL

===== TEST 3: Empty list =====
Handled NULL list correctly

===== TEST 4: NULL function =====
Handled NULL function correctly

===== TEST 5: NULL del function
HELLO -> WORLD -> LIBFT -> NULL

===== ALL TESTS COMPLETED =====

*/