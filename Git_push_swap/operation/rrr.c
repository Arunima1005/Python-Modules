/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:46:16 by olistoke          #+#    #+#             */
/*   Updated: 2026/04/07 12:10:29 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	rrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = NULL;
	last = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	if (*a_stack && (*a_stack)->next)
		rrotate(a_stack);
	if (*b_stack && (*b_stack)->next)
		rrotate(b_stack);
	ft_putstr_fd("rrr\n", 1);
	ops_count->rrr++;
	ops_count->total++;
}
