/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_utlis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:07:58 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/07 21:07:42 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_error_exit(t_stack **a, char **nums)
{
	if (nums)
		ft_free_split(nums);
	if (a && *a)
		ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
