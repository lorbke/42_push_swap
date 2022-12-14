/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:37:20 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/08 14:33:54 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_top_of_stack(t_stack *stack)
{
	int	temp;

	temp = stack->index[stack->count - 1];
	stack->index[stack->count - 1] = stack->index[stack->count - 2];
	stack->index[stack->count - 2] = temp;
}

void	ps_push_to_stack(t_stack *from, t_stack *to)
{
	to->index[to->count] = from->index[from->count - 1];
	to->count++;
	from->count--;
}

void	ps_rotate_stack_up(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack->index[stack->count - 1];
	i = 0;
	while (i < stack->count - 1)
	{
		stack->index[stack->count - 1 - i]
			= stack->index[stack->count - 2 - i];
		i++;
	}
	stack->index[0] = temp;
}

void	ps_rotate_stack_down(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack->index[0];
	i = 0;
	while (i < stack->count - 1)
	{
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->index[stack->count - 1] = temp;
}
