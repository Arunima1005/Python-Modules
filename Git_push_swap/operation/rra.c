/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:50:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 12:10:06 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	rra(t_stack **a_stack, t_ops *ops_count)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = NULL;
	last = *a_stack;
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
	ft_putstr_fd("rra\n", 1);
	ops_count->rra++;
	ops_count->total++;
}
