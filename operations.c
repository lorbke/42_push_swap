/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:37:20 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 22:10:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printing: assign an id to stack struct and 
// print id at end of operation function

#include "push_swap.h"

void	swap_top_of_stack(t_stack *stack, t_vector *vector, int combine)
{
	int	temp;

	if (stack->count >= 2)
	{
		temp = stack->index[0];
		stack->index[0] = stack->index[1];
		stack->index[1] = temp;
	}
	ft_vector_push_back(vector, 's', 1);
	if (!combine)
	{
		ft_vector_push_back(vector, stack->id, 1);
		ft_vector_push_back(vector, '\n', 1);
	}
}

void	push_to_stack(t_stack *from, t_stack *to, t_vector *vector)
{
	if (from->count > 0)
	{
		to->index[to->count] = from->index[from->count - 1];
		to->count++;
		from->count--;
	}
}

void	rotate_stack_up(t_stack *stack, t_vector *vector, int combine)
{
	int	i;
	int	temp;

	if (stack->count > 1)
	{
		temp = stack->index[stack->count - 1];
		i = 0;
		while (i < stack->count)
		{
			stack->index[stack->count - 1 - i]
				= stack->index[stack->count - 2 - i];
			i++;
		}
		stack->index[0] = temp;
		ft_vector_push_back(vector, 'r', 1);
		if (!combine)
		{
			ft_vector_push_back(vector, stack->id, 1);
			ft_vector_push_back(vector, '\n', 1);
		}
	}
}

void	rotate_stack_down(t_stack *stack, t_vector *vector, int combine)
{
	int	i;
	int	temp;

	if (stack->count > 1)
	{
		temp = stack->index[0];
		i = 0;
		while (i < stack->count)
		{
			stack->index[i] = stack->index[i + 1];
			i++;
		}
		stack->index[stack->count - 1] = temp;
		ft_vector_push_back(vector, 'r', 2);
		if (!combine)
		{
			ft_vector_push_back(vector, stack->id, 1);
			ft_vector_push_back(vector, '\n', 1);
		}
	}
}
