/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:35:45 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 21:23:26 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

// pushing the largest first
void	ft_sort_b(t_stack **b_stack, int pos, t_ops *ops_count)
{
	int	size;
	int	step;

	size = ft_stack_size(*b_stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b_stack, ops_count);
	}
	else
	{
		step = size - pos;
		while (step-- > 0)
			rrb(b_stack, ops_count);
	}
}

void	ft_init_ops(t_ops *ops)
{
	ops->total = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->strategy = NULL;
}

void	ft_parse_string(char *arg, t_stack **a)
{
	char	**nums;
	int		i;
	int		value;
	int		error;

	error = 0;
	i = 0;
	nums = ft_split(arg, ' ');
	if (!nums)
		exit(1);
	i = 0;
	while (nums[i])
	{
		if (!ft_is_number(nums[i]))
			ft_error_exit(a, nums);
		error = 0;
		value = ft_atoi_minmax(nums[i], &error);
		if (error)
			ft_error_exit(a, nums);
		ft_add_back(value, a);
		i++;
	}
	ft_free_split(nums);
}

void	ft_small_number_strategy(t_flags flags, t_ops *ops_count)
{
	if (flags.adaptive)
		ops_count->strategy = "Adaptive / O(n²)";
	else if (flags.medium)
		ops_count->strategy = "Medium / O(n√n)";
	else if (flags.complex)
		ops_count->strategy = "Complex / O(n log n)";
	else if (flags.simple)
		ops_count->strategy = "Simple / O(n²)";
	else
		ops_count->strategy = "Adaptive / O(n²)";
}
