/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:31:15 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/18 20:58:17 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_largest(t_stack *stack, int edge)
{
	int	highest_value;
	int	i;

	highest_value = 0;
	i = stack->count - 1;
	while (i >= stack->count - edge)
	{
		if (highest_value < stack->index[i])
			highest_value = stack->index[i];
		i--;
	}
	return (highest_value);
}

static int	move_to_largest(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	largest;
	int	rotations;

	largest = get_largest(stacks[1], edge);
	rotations = 0;
	while (current->index[current->count - 1] != largest)
	{
		operate(stacks, vector, 6);
		rotations++;
	}
	return (rotations);
}

void	bubblesort(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	pushes;
	int	j;

	pushes = 0;
	j = move_to_largest(current, edge, stacks, vector);
	printf("j: %i\n", j);
	operate(stacks, vector, 3);
	edge--;
	while (pushes < edge)
	{
		while (j < edge - pushes)
		{
			if (current->index[current->count - 1] == stacks[0]->index[stacks[0]->count - 1] - 1)
			{
				operate(stacks, vector, 3);
				pushes++;
			}
			else
				operate(stacks, vector, 6);
			j++;
		}
		operate(stacks, vector, 9);
		write(1, "1", 1);
		j = 0;
		while (j < edge - pushes)
		{
			if (current->index[current->count - 1] == stacks[0]->index[stacks[0]->count - 1] - 1)
			{
				operate(stacks, vector, 3);
				pushes++;
			}
			else
				operate(stacks, vector, 9);
			j++;
		}
	}
}
