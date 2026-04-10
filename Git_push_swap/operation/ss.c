/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:46:00 by olistoke          #+#    #+#             */
/*   Updated: 2026/04/07 12:11:00 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	ss(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	t_stack	*a_first;
	t_stack	*a_second;
	t_stack	*b_first;
	t_stack	*b_second;

	if (*a_stack && !(*a_stack)->next)
	{
		a_first = *a_stack;
		a_second = (*a_stack)->next;
		a_first->next = a_second->next;
		a_second->next = a_first;
		*a_stack = a_second;
	}
	if (*b_stack && (*b_stack)->next)
	{
		b_first = *b_stack;
		b_second = (*b_stack)->next;
		b_first->next = b_second->next;
		b_second->next = b_first;
		*b_stack = b_second;
	}
	ft_putstr_fd("ss\n", 1);
	ops_count->ss++;
	ops_count->total++;
}
