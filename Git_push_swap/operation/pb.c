/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:02:46 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 12:35:41 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	pb(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	t_stack	*tmp;

	if (!*a_stack)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = *b_stack;
	*b_stack = tmp;
	ft_putstr_fd("pb\n", 1);
	ops_count->pb++;
	ops_count->total++;
}
