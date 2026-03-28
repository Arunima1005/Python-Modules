/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:08:42 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 20:30:07 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_new_content(int content)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_add_back(int content, t_stack **stack)
{
	t_stack *new = ft_new_content(content);
	 if (*stack == NULL){
	 	*stack = new;
		return ;
	 }
	t_stack *tmp = *stack;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
int ft_stack_size(t_stack *stack)
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
void ft_stack_print(t_stack *stack)
{
	while (stack->next)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	printf("%d\n", stack->content);
}

int ft_find_min(t_stack *a_stack)
{
	int	min;
	int	i;
	int pos;

	min = a_stack->content;
	i = 0;
	pos = 0;
	while(a_stack)
	{
		if (a_stack->content < min)
		{
			min = a_stack->content;
			pos = i;
		}
		a_stack = a_stack->next;
		i++;
	}
	return (pos);
}

void ft_selection_sort(t_stack **a_stack, t_stack **b_stack)
{

	int	size;// = ft_stack_size(*a_stack);
	int	pos;
	int	ops_count;
	int step;

	ops_count = 0;
	while (*a_stack)
	{
		size = ft_stack_size(*a_stack);;
		pos = ft_find_min(*a_stack);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a_stack,&ops_count);
		}
		else
		{
			step = size - pos;
			while (step-- > 0)
				rra(a_stack,&ops_count);
		}
		pb(a_stack, b_stack, &ops_count);
		size--;
	}

	while (*b_stack)
	{
		pa(a_stack, b_stack, &ops_count);
	}
	printf("Total ops: %d\n", ops_count);
	//ft_stack_print(*a_stack);
}

int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int 	count = 0;

	ft_add_back(23, &a);
	ft_add_back(4, &a);
	ft_add_back(10, &a);
	ft_add_back(50, &a);
	printf("Before-----------\n");
	ft_stack_print(a);

	ft_selection_sort(&a,&b);
	printf("After-----------\n");
	ft_stack_print(a);
}