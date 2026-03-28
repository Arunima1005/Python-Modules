/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:02:46 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 20:33:09 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void pb(t_stack **a_stack, t_stack **b_stack, int *ops_count)
{
	t_stack	*tmp;

	if (!*a_stack)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = *b_stack;
	*b_stack = tmp;
	printf("pb\n");
	(*ops_count)++;	
}