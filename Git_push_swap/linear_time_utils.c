/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   linear_time_utils.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: olistoke <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 17:40:29 by olistoke       #+#    #+#                */
/*   Updated: 2026/04/08 17:41:38 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	ft_sort_to_five(t_stack **a, t_stack **b, t_ops *ops_count)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		ft_sort_two(a, ops_count);
	else if (size == 3)
		ft_sort_three(a, ops_count);
	else if (size == 4)
		ft_sort_four(a, b, ops_count);
	else if (size == 5)
		ft_sort_five(a, b, ops_count);
	return ;
}

void	ft_move_min_to_top(t_stack **a, t_ops *ops_count)
{
	int	pos;
	int	size;

	pos = ft_find_min(*a);
	size = ft_stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, ops_count);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, ops_count);
	}
}
