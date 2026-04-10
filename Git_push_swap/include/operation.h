/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:08:02 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/08 17:38:54 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "push_swap.h"

typedef struct s_ops
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	char	*strategy;
}	t_ops;

typedef struct s_stack	t_stack;
void			sa(t_stack **stack, t_ops *ops_count);
void			ra(t_stack **a_stack, t_ops *ops_count);
void			pb(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count);
void			pa(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count);
void			rra(t_stack **a_stack, t_ops *ops_count);
void			rb(t_stack **b_stack, t_ops *ops_count);
void			rrb(t_stack **b_stack, t_ops *ops_count);
void			ft_print_bench_ops(t_ops *ops_count, double disorder);
void			ft_print_bench_ops_2(t_ops *ops_count);
void			ft_sort_b(t_stack **b_stack, int pos, t_ops *ops_count);
void			ft_selection_sort(t_stack **a_stack, t_stack **b_stack,
					t_ops *ops_count);
void			ft_chunk_sort(t_stack **a_stack, t_stack **b_stack,
					t_ops *ops_count);
void			ft_radix_sort(t_stack **a_stack, t_stack **b_stack,
					t_ops *ops_count);
void			ft_assign_index(t_stack *a_stack);
void			ft_push_chunks(t_stack **a_stack, t_stack **b_stack,
					t_ops *ops_count);
void			ft_init_ops(t_ops *ops);
#endif
