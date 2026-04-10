/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:26:08 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 12:10:17 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	rrb(t_stack **b_stack, t_ops *ops_count)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b_stack || !(*b_stack)->next)
		return ;
	tmp = NULL;
	last = *b_stack;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *b_stack;
	*b_stack = last;
	ft_putstr_fd("rrb\n", 1);
	ops_count->rrb++;
	ops_count->total++;
}
