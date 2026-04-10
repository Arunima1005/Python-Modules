/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:59:14 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/08 15:14:49 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

// Finding the smallest one from the stack a
int	ft_find_min(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->content;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

// Finding the largest one from the stack a
int	ft_find_max(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	max = stack->content;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

// Square Root Function
int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
