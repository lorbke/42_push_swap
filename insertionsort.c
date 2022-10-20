/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:21:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 23:27:26 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest(t_stack *stack)
{
	int	highest;
	int	i;

	highest = 0;
	i = 0;
	while (i < stack->count)
	{
		if (stack->index[i] > highest)
			highest = stack->index[i];
		i++;
	}
	return (highest);
}

static int	get_direction(int number, t_stack *stack)
{
	int	top;
	int	bottom;
	int	temp;

	top = 0;
	bottom = 0;
	while (stack->index[stack->count - 1 - top] != number)
		top++;
	while (stack->index[0 + bottom] != number)
		bottom++;
	return (bottom + 1 - top);
}

static int	rotate_direction(int direction, t_stack **stacks, t_vector *vector)
{
	if (direction < 0)
	{
		operate(stacks, vector, 9);
		return (-1);
	}
	else
	{
		operate(stacks, vector, 6);
		return (1);
	}
}

void	insertionsort(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	highest;
	int	direction;

	while (edge)
	{
		highest = get_highest(stacks[1]);
		// printf("highest: %i\n", highest);
		direction = get_direction(highest, stacks[1]);
		// printf("direction: %i\n", direction);
		while (stacks[1]->index[stacks[1]->count - 1] != highest)
		{
			// print_stack(stacks[0]);
			// print_stack(stacks[1]);
			// sleep(1);
			rotate_direction(direction, stacks, vector);
		}
		operate(stacks, vector, 3);
		edge--;
	}
}
