/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:08:42 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/29 20:28:56 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Creating new node for stack
t_stack *ft_new_content(int content)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}
//Inserting value in the stack
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
//Calculating stack size
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
//Displaying the stack
void ft_stack_print(t_stack *stack)
{
	while (stack)
	{
		//printf("%d(index:%d) ", stack->content, stack->index);
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}
//Finding the smallest one from the stack a
int ft_find_min(t_stack *stack)
{
	int	min;
	int pos;
	int	i;

	min = stack->content;
	pos = 0;
	i = 0;
	while(stack)
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

//Finding the largest one from the stack a
int ft_find_max(t_stack *stack)
{
	int	max;
	int pos;
	int	i;

	max = stack->content;
	pos = 0;
	i = 0;
	while(stack)
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

//Selection sort simple algorithm
void ft_selection_sort(t_stack **a_stack, t_stack **b_stack, int *ops_count)
{
	int	size;// = ft_stack_size(*a_stack);
	int	pos;
	int step;
	
	while (*a_stack)
	{
		size = ft_stack_size(*a_stack);;
		pos = ft_find_min(*a_stack);
		if (pos <= size / 2) //if the position is closer to the top
		{
			while (pos-- > 0)
				ra(a_stack,ops_count);
		}
		else // //if the position is closer to the bottom
		{
			step = size - pos;
			while (step-- > 0)
				rra(a_stack,ops_count);
		}
		pb(a_stack, b_stack, ops_count);
	}
	while (*b_stack)
	{
		pa(a_stack, b_stack, ops_count);
	}
}
//normal atoi function used for argv (string->int)
int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}
//Assigning index to the each number - ascending order (sorted)
void ft_assign_index(t_stack *a_stack) 
{
	t_stack		*tmp;
	t_stack 	*ctmp;
	int			index;

	tmp = a_stack;
	while (tmp)
	{
		index = 0;
		ctmp = a_stack;
		while (ctmp)
		{
			if (ctmp->next < tmp->next)
				index++;
			ctmp = ctmp->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
// Square Root Function
int ft_sqrt(int n)
{
    int i = 0;

    while (i * i <= n)
        i++;
    return (i - 1);
}
// Making chunks and pushing to stack b (Smaller numbers are closer to the bottom - Larger numbers are closer to top)
void ft_push_chunks(t_stack **a_stack, t_stack **b_stack, int *ops_count)
{
	int	size = ft_stack_size(*a_stack);
	int chunk = ft_sqrt(size) + 1;
	int	i;

	i = 0;
	while (*a_stack)
	{
		if ((*a_stack)->index <= i)
		{
			pb(a_stack,b_stack, ops_count);
			rb(b_stack,ops_count);// to move the smaller number in the bottom of stack b
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
//pushing the largest first
void ft_sort_b(t_stack **b_stack, int pos, int *ops_count)
{
	int size = ft_stack_size(*b_stack);
    int step;

    if (pos <= size / 2)//if the position is closer to the top
    {
        while (pos-- > 0)
            rb(b_stack, ops_count);
    }
    else //if the position is closer to the bottom
    {
        step = size - pos;
        while (step-- > 0)
            rrb(b_stack, ops_count);
    }
}
//Chunk based sorting algorithm
void ft_chunk_sort(t_stack **a_stack, t_stack **b_stack, int *ops_count)
{
    int	pos;
	ft_push_chunks(a_stack, b_stack, ops_count);
	while (*b_stack)
	{
		pos = ft_find_max(*b_stack);
		ft_sort_b(b_stack, pos, ops_count);// Bring largest to top to b_stack
		pa(a_stack, b_stack, ops_count); //Push back to a
	}
}

int main(int argc, char **argv)
//int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int 	ops_count = 0;
	int 	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		ft_add_back(atoi(argv[i]), &a);
		i++;
	}
	//displaying before sort
	printf("Before-----------\n");
	ft_stack_print(a);

	//====selection sort calling=======
	//ft_selection_sort(&a,&b,&ops_count);

	
	//== chunk based sort calling ======
	ft_assign_index(a);
	ft_chunk_sort(&a, &b, &ops_count);

	//Displaying after sort
	printf("After-----------\n");
	ft_stack_print(a);
	printf("\nTotal operations : %d\n", ops_count);
}