/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:57:50 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 12:09:40 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	rb(t_stack **b_stack, t_ops *ops_count)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!*b_stack || !(*b_stack)->next)
		return ;
	first = *b_stack;
	*b_stack = first->next;
	tmp = *b_stack;
	while (tmp->next)
		tmp = tmp->next;
	first->next = NULL;
	tmp->next = first;
	ft_putstr_fd("rb\n", 1);
	ops_count->rb++;
	ops_count->total++;
}
