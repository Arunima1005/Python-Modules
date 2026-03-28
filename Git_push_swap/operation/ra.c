/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:10:49 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 20:35:37 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void ra(t_stack **a_stack, int *ops_count)
{
	t_stack	*first;
	t_stack *tmp;
	
	if (!*a_stack || !(*a_stack)->next)
		return ;
	first = *a_stack;
	*a_stack = first->next;
	tmp = *a_stack;
	while (tmp->next)
		tmp = tmp->next;
	first->next = NULL;
	tmp->next = first;
	printf("ra\n");
	(*ops_count)++;
}