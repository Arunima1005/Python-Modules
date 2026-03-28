/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:04:09 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 18:44:43 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "operation.h"

void pa(t_stack **a_stack, t_stack **b_stack, int *ops_count)
{
	t_stack *tmp;

	if (!*b_stack)
		return ;
	tmp = *b_stack;
	*b_stack = (*b_stack)->next;
	tmp->next = *a_stack;
	*a_stack = tmp;
	printf("pa\n");
	(*ops_count)++;
}
