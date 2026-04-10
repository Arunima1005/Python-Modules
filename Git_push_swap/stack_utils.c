/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                       :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:52:42 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/09 16:41:41 by olistoke       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

// Creating new node for stack
t_stack	*ft_new_content(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Inserting value in the stack
void	ft_add_back(int content, t_stack **stack)
{
	t_stack	*new;
	t_stack	*tmp;

	new = ft_new_content(content);
	if (!new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// Calculating stack size
int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	isdup_stack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*check;

	tmp = a;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->content == check->content)
				return (1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
