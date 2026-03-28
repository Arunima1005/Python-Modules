/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 20:36:03 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void rra(t_stack **a_stack, int *ops_count)
{
	t_stack *tmp = NULL;
	t_stack *last = *a_stack;

	if (!*a_stack || !(*a_stack)->next)
		return ;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *a_stack;
	*a_stack = last;

	printf("rra\n");
	(*ops_count)++;
}