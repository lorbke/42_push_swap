/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:21:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 22:32:00 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest(int top, int bottom, t_stack *stack)
{
	int	highest;

	highest = 0;
	while (top)
	{
		if (stack->index[stack->count - top] > highest)
			highest = stack->index[stack->count - top];
		top--;
	}
	while (bottom)
	{
		if (stack->index[0 + bottom - 1] > highest)
			highest = stack->index[0 + bottom - 1];
		bottom--;
	}
	return (highest);
}

static int	get_direction(int top, int bottom, int number, t_stack *stack)
{
	int	temp;

	temp = top;
	while (top && stack->index[stack->count - 1 - temp + top] != number)
		top--;
	temp = bottom;
	while (bottom && stack->index[0 + temp - bottom] != number)
		bottom--;
	return (top - bottom);
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
	int	top;
	int	bottom;
	int	highest;
	int	direction;

	if (swap == 1)
	{
		top = edge;
		bottom = 0;
	}
	else
	{
		top = 0;
		bottom = edge;
	}
	// highest = get_highest(top, bottom, stacks[1]);
	// direction = get_direction(highest, stacks[1]);
	// rotate_direction(direction, stacks, vector);
	while (edge)
	{
		// printf("top: %i\n", top);
		// printf("bottom: %i\n", bottom);
		highest = get_highest(top, bottom, stacks[1]);
		// printf("highest: %i\n", highest);
		direction = get_direction(top, bottom, highest, stacks[1]);
		// printf("direction: %i\n", direction);
		while (stacks[1]->index[stacks[1]->count - 1] != highest)
		{
			swap = rotate_direction(direction, stacks, vector);
			top -= swap;
			bottom += swap;
			// printf("top: %i\n", top);
			// printf("bottom: %i\n", bottom);
		}
		operate(stacks, vector, 3);
		top--;
		edge--;
	}
}
