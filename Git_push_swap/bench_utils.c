/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:12:28 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 21:06:37 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

double	ft_compute_disorder(t_stack *a_stack)
{
	t_stack	*tmp;
	t_stack	*tmpnext;
	int		mistakes;
	int		total_pairs;

	tmp = a_stack;
	mistakes = 0;
	total_pairs = 0;
	while (tmp)
	{
		tmpnext = tmp->next;
		while (tmpnext)
		{
			total_pairs++;
			if (tmp->content > tmpnext->content)
				mistakes++;
			tmpnext = tmpnext->next;
		}
		tmp = tmp->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

void	ft_print_bench_ops(t_ops *ops_count, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble_fd(disorder * 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(ops_count->strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(ops_count->total, 2);
	ft_print_bench_ops_2(ops_count);
}

void	ft_print_bench_ops_2(t_ops *ops_count)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(ops_count->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops_count->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops_count->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops_count->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops_count->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ops_count->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops_count->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops_count->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops_count->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops_count->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops_count->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_flag_count(int argc, char **argv, t_flags *flag, int *start)
{
	int	i;

	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			flag->simple = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			flag->medium = 1;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			flag->complex = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			flag->adaptive = 1;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			flag->bench = 1;
		else
			break ;
		i++;
	}
	*start = i;
}
