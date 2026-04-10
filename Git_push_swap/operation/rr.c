/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:46:09 by olistoke          #+#    #+#             */
/*   Updated: 2026/04/07 12:09:56 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	first->next = NULL;
	tmp->next = first;
}

void	rr(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	if (*a_stack && (*a_stack)->next)
		rotate(a_stack);
	if (*b_stack && (*b_stack)->next)
		rotate(b_stack);
	ft_putstr_fd("rr\n", 1);
	ops_count->rr++;
	ops_count->total++;
}
