/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:22:23 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 21:11:32 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

// Selection sort simple algorithm
void	ft_selection_sort(t_stack **a_stack, t_stack **b_stack,
		t_ops *ops_count)
{
	int	pos;
	int	step;
	int	size;

	while (*a_stack)
	{
		size = ft_stack_size(*a_stack);
		pos = ft_find_min(*a_stack);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a_stack, ops_count);
		}
		else
		{
			step = size - pos;
			while (step-- > 0)
				rra(a_stack, ops_count);
		}
		pb(a_stack, b_stack, ops_count);
	}
	while (*b_stack)
	{
		pa(a_stack, b_stack, ops_count);
	}
}

void	ft_chunk_sort(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	int	pos;

	ft_push_chunks(a_stack, b_stack, ops_count);
	while (*b_stack)
	{
		pos = ft_find_max(*b_stack);
		ft_sort_b(b_stack, pos, ops_count);
		pa(a_stack, b_stack, ops_count);
	}
}

void	ft_radix_sort(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_stack_size(*a_stack);
	max_bits = 0;
	i = -1;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((*a_stack)->index >> i) & 1)
				ra(a_stack, ops_count);
			else
				pb(a_stack, b_stack, ops_count);
		}
		while (*b_stack)
			pa(a_stack, b_stack, ops_count);
	}
}

// normal atoi function used for argv (string->int)
// Assigning index to the each number - ascending order (sorted)
void	ft_assign_index(t_stack *a_stack)
{
	t_stack	*tmp;
	t_stack	*ctmp;
	int		index;

	tmp = a_stack;
	while (tmp)
	{
		index = 0;
		ctmp = a_stack;
		while (ctmp)
		{
			if (ctmp->content < tmp->content)
				index++;
			ctmp = ctmp->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

void	ft_push_chunks(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
{
	int	size;
	int	chunk;
	int	i;

	size = ft_stack_size(*a_stack);
	chunk = ft_sqrt(size) + 1;
	i = 0;
	while (*a_stack)
	{
		if ((*a_stack)->index <= i)
		{
			pb(a_stack, b_stack, ops_count);
			rb(b_stack, ops_count);
			i++;
		}
		else if ((*a_stack)->index <= i + chunk)
		{
			pb(a_stack, b_stack, ops_count);
			i++;
		}
		else
			ra(a_stack, ops_count);
	}
}
