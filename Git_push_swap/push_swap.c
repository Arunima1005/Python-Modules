/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:08:42 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/09 17:09:21 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

void	ft_adaptive_selection(t_stack **a_stack,
	t_stack **b_stack, t_ops *ops_count)
{
	double	disorder;

	disorder = ft_compute_disorder(*a_stack);
	if (disorder < 0.2)
	{
		ops_count->strategy = "Adaptive / O(n²)";
		ft_selection_sort(a_stack, b_stack, ops_count);
	}
	else if (disorder < 0.5)
	{
		ops_count->strategy = "Adaptive / O(n√n)";
		ft_assign_index(*a_stack);
		ft_chunk_sort(a_stack, b_stack, ops_count);
	}
	else
	{
		ops_count->strategy = "Adaptive / O(n log n)";
		ft_assign_index(*a_stack);
		ft_radix_sort(a_stack, b_stack, ops_count);
	}
}

void	ft_strategy_selection(t_stack **a_stack, t_stack **b_stack,
		t_flags flag, t_ops *ops_count)
{
	if (flag.simple)
	{
		ops_count->strategy = "Simple / O(n²)";
		ft_selection_sort(a_stack, b_stack, ops_count);
	}
	else if (flag.medium)
	{
		ops_count->strategy = "Medium / O(n√n)";
		ft_assign_index(*a_stack);
		ft_chunk_sort(a_stack, b_stack, ops_count);
	}
	else if (flag.complex)
	{
		ops_count->strategy = "Complex / O(n log n)";
		ft_assign_index(*a_stack);
		ft_radix_sort(a_stack, b_stack, ops_count);
	}
	else
		ft_adaptive_selection(a_stack, b_stack, ops_count);
}

// SPLIT STRING AND ALSO CHECK FOR ERRORS
void	string_converter(int argc, char **argv, int start, t_stack **a)
{
	int	i;
	int	error;
	int	value;

	if (argc == (start + 1))
	{
		ft_parse_string(argv[start], a);
		return ;
	}
	i = start;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			ft_error_exit(a, NULL);
		error = 0;
		value = ft_atoi_minmax(argv[i], &error);
		if (error)
			ft_error_exit(a, NULL);
		ft_add_back(value, a);
		i++;
	}
}

void	ft_build_sort(t_stack **a, t_stack **b, t_ops *ops_count, t_flags flags)
{
	double	disorder;

	disorder = ft_compute_disorder(*a);
	if (disorder == 0.0)
	{
		ft_free_stack(a);
		return ;
	}
	if (ft_stack_size(*a) <= 5)
	{
		ft_small_number_strategy(flags, ops_count);
		ft_sort_to_five(a, b, ops_count);
	}
	else
		ft_strategy_selection(a, b, flags, ops_count);
	if (flags.bench)
		ft_print_bench_ops(ops_count, disorder);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	ops_count;
	int		start;
	t_flags	flags;

	a = NULL;
	b = NULL;
	ft_init_ops(&ops_count);
	ft_flag_count(argc, argv, &flags, &start);
	if (start >= argc)
		return (0);
	string_converter(argc, argv, start, &a);
	if (isdup_stack(a))
		ft_error_exit(&a, NULL);
	ft_build_sort(&a, &b, &ops_count, flags);
	return (ft_free_stack(&a), ft_free_stack(&b), 0);
}
