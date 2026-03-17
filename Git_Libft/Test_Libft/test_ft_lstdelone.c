/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:58:44 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/16 18:56:51 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/* delete function used by ft_lstdelone */
void	del_content(void *content)
{
	printf("Deleting content: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	printf("===== TEST 1: Normal deletion =====\n");

	t_list *node1 = ft_lstnew(strdup("hello"));

	ft_lstdelone(node1, del_content);

	printf("Node deleted successfully\n");


	printf("\n===== TEST 2: NULL node =====\n");

	ft_lstdelone(NULL, del_content);

	printf("Handled NULL node safely\n");


	printf("\n===== TEST 3: NULL del function =====\n");

	t_list *node2 = ft_lstnew(strdup("world"));

	ft_lstdelone(node2, NULL);

	printf("Handled NULL del function\n");

	/* since del wasn't called, we must free manually */
	free(node2->content);
	free(node2);


	printf("\n===== TEST 4: Ensure next node NOT freed =====\n");

	t_list *nodeA = ft_lstnew(strdup("AAA"));
	t_list *nodeB = ft_lstnew(strdup("BBB"));

	nodeA->next = nodeB;

	ft_lstdelone(nodeA, del_content);

	printf("Next node content still exists: %s\n", (char *)nodeB->content);

	free(nodeB->content);
	free(nodeB);


	printf("\n===== TEST 5: Empty string content =====\n");

	t_list *node3 = ft_lstnew(strdup(""));

	ft_lstdelone(node3, del_content);

	printf("Empty string node deleted\n");


	printf("\n===== TEST 6: Large content =====\n");

	char *big = malloc(1000);
	strcpy(big, "Large content test");

	t_list *node4 = ft_lstnew(big);

	ft_lstdelone(node4, del_content);

	printf("Large content node deleted\n");


	printf("\n===== ALL TESTS COMPLETED SUCCESSFULLY =====\n");

	return (0);
}

