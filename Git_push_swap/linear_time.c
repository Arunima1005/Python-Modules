/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   linear_time.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: olistoke <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 13:33:40 by olistoke       #+#    #+#                */
/*   Updated: 2026/04/08 17:38:43 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	ft_sort_two(t_stack **a, t_ops *ops_count)
{
	if ((*a)->content > (*a)->next->content)
		sa(a, ops_count);
}

void	ft_sort_three(t_stack **a, t_ops *ops_count)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x < y && y < z)
		return ;
	if (x > y && y > z)
	{
		sa(a, ops_count);
		rra(a, ops_count);
	}
	else if (x > y && x > z && y < z)
		ra(a, ops_count);
	else if (x < y && x > z)
		rra(a, ops_count);
	else if (x > y && x < z)
		sa(a, ops_count);
	else if (x < y && y > z)
	{
		sa(a, ops_count);
		ra(a, ops_count);
	}
}

void	ft_sort_four(t_stack **a, t_stack **b, t_ops *ops_count)
{
	ft_move_min_to_top(a, ops_count);
	pb(a, b, ops_count);
	ft_sort_three(a, ops_count);
	pa(a, b, ops_count);
}

void	ft_sort_five(t_stack **a, t_stack **b, t_ops *ops_count)
{
	ft_move_min_to_top(a, ops_count);
	pb(a, b, ops_count);
	ft_move_min_to_top(a, ops_count);
	pb(a, b, ops_count);
	ft_sort_three(a, ops_count);
	pa(a, b, ops_count);
	pa(a, b, ops_count);
}
