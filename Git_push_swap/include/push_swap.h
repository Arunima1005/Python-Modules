/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:09:00 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/08 17:39:44 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_ops	t_ops;

typedef struct s_stack
{
	int				content;
	int				index; // Required this for Chunk Based Algorithm
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

t_stack		*ft_new_content(int content);
void		ft_add_back(int content, t_stack **stack);
int			ft_stack_size(t_stack *stack);
void		ft_stack_print(t_stack *stack);
int			isdup_stack(t_stack *a);
void		ft_free_stack(t_stack **stack);
int			ft_is_number(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_sqrt(int n);
int			ft_find_max(t_stack *stack);
int			ft_find_min(t_stack *stack);
void		ft_free_stack(t_stack **stack);
void		ft_free_split(char **arr);
double		ft_compute_disorder(t_stack *a_stack);
void		ft_flag_count(int argc, char **argv, t_flags *flag, int *start);
void		ft_error_exit(t_stack **a, char **nums);
void		ft_sort_to_five(t_stack **a, t_stack **b, t_ops *ops_count);
void		ft_move_min_to_top(t_stack **a, t_ops *ops_count);
void		ft_sort_two(t_stack **a, t_ops *ops_count);
void		ft_sort_three(t_stack **a, t_ops *ops_count);
void		ft_sort_four(t_stack **a, t_stack **b, t_ops *ops_count);
void		ft_sort_five(t_stack **a, t_stack **b, t_ops *ops_count);
void		ft_build_sort(t_stack **a, t_stack **b, t_ops *ops_count,
				t_flags flags);
void		string_converter(int argc, char **argv, int start, t_stack **a);
void		ft_strategy_selection(t_stack **a_stack, t_stack **b_stack,
				t_flags flag, t_ops *ops_count);
void		ft_adaptive_selection(t_stack **a_stack, t_stack **b_stack,
				t_ops *ops_count);
void		ft_parse_string(char *arg, t_stack **a);
void		ft_small_number_strategy(t_flags flags,	t_ops *ops_count);

#endif
