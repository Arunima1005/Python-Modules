/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:08:02 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/28 19:14:42 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

//#include "push_swap.h"
typedef struct s_stack t_stack;
void sa(t_stack **stack, int *ops_count);
void ra(t_stack **a_stack, int *ops_count);
void pb(t_stack **a_stack, t_stack **b_stack, int *ops_count);
void pa(t_stack **a_stack, t_stack **b_stack, int *ops_count);
void rra(t_stack **a_stack, int *ops_count);

# endif
