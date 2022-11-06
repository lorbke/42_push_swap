/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:21:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/05 19:15:42 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_insert_pos(int insert, int max, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->index[i] > insert && stack->index[i + 1] == max)
			return (stack->index[i]);
		if (stack->index[i] > insert
			&& stack->index[i + 1] < insert)
			return (stack->index[i]);
		i++;
	}
	return (stack->index[stack->count - 1]);
}

static int	get_direction(int number, t_stack *stack)
{
	int	top;
	int	bottom;

	if (stack->index[stack->count - 1] == number)
		return (0);
	top = 0;
	bottom = 0;
	while (stack->index[stack->count - 1 - top] != number)
	{
		top++;
	}
	while (stack->index[0 + bottom] != number)
	{
		bottom++;
	}
	if (bottom - top == 0)
		return (bottom + 1 - top);
	return (bottom - top);
}

static void	
	rotate_direction(int dir_a, int dir_b, t_stack **stacks, t_vector *vector)
{
	if (dir_a < 0 && dir_b < 0)
		operate(stacks, vector, 10);
	else if (dir_a > 0 && dir_b > 0)
		operate(stacks, vector, 7);
	else if (dir_a < 0 && dir_b > 0)
	{
		operate(stacks, vector, 8);
		operate(stacks, vector, 6);
	}
	else if (dir_a > 0 && dir_b < 0)
	{
		operate(stacks, vector, 5);
		operate(stacks, vector, 9);
	}
	else if (dir_a < 0 && dir_b == 0)
		operate(stacks, vector, 8);
	else if (dir_a > 0 && dir_b == 0)
		operate(stacks, vector, 5);
	else if (dir_a == 0 && dir_b > 0)
		operate(stacks, vector, 6);
	else if (dir_a == 0 && dir_b < 0)
		operate(stacks, vector, 9);
}

static void	
	rotate_to_positions(int next, int max, t_stack **stacks, t_vector *vector)
{
	int	position;
	int	direction_a;
	int	direction_b;

	position = get_insert_pos(next, max, stacks[0]);
	direction_a = get_direction(position, stacks[0]);
	direction_b = get_direction(next, stacks[1]);
	while (stacks[0]->index[stacks[0]->count - 1] != position
		|| stacks[1]->index[stacks[1]->count - 1] != next)
	{
		if (stacks[0]->index[stacks[0]->count - 1] == position)
			direction_a = 0;
		if (stacks[1]->index[stacks[1]->count - 1] == next)
			direction_b = 0;
		rotate_direction(direction_a, direction_b, stacks, vector);
	}
}

void	insertionsort(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	*sequence;
	int	max;
	int	next;
	int	i;

	sequence = get_lds(stacks[1], edge, swap);
	max = stacks[0]->index[0];
	i = 0;
	while (edge)
	{
		if (sequence[i] != -1 && edge > 4)
			next = sequence[i++];
		else
			next = get_highest(stacks[1]);
		rotate_to_positions(next, max, stacks, vector);
		operate(stacks, vector, 3);
		edge--;
	}
	i = get_direction(max, stacks[0]);
	while (stacks[0]->index[0] != max)
	{
		rotate_direction(i, 0, stacks, vector);
	}
}
