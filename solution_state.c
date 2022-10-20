/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:58:20 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/19 23:46:56 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubblesort_b(int edge, t_stack **stacks)
{
	int	i;

	while (edge)
	{
		i = 0;
		while (i < edge - 1)
		{
			if (stacks[1]->index[stacks[1]->count - 1 - i]
				< stacks[1]->index[stacks[1]->count - 2 - i])
				swap(&stacks[1]->index[stacks[1]->count - 1 - i],
					&stacks[1]->index[stacks[1]->count - 2 - i]);
			i++;
		}
		edge--;
	}
}

static void	bubblesort_a(int edge, t_stack **stacks)
{
	int	i;

	while (edge)
	{
		i = 0;
		while (i < edge - 1)
		{
			if (stacks[0]->index[stacks[0]->count - 1 - i]
				> stacks[0]->index[stacks[0]->count - 2 - i])
				swap(&stacks[0]->index[stacks[0]->count - 1 - i],
					&stacks[0]->index[stacks[0]->count - 2 - i]);
			i++;
		}
		edge--;
	}
}

void	get_solution_state_b(int edge, t_stack **stacks)
{
	int	temp;

	if (edge > stacks[1]->count)
		edge = stacks[1]->count;
	temp = edge;
	while (edge)
	{
		stacks[0]->count++;
		stacks[0]->index[stacks[0]->count - 1] 
			= stacks[1]->index[stacks[1]->count - 1];
		stacks[1]->count--;
		edge--;
	}
	bubblesort_a(temp, stacks);
}

void	get_solution_state_a(int edge, t_stack **stacks)
{
	int	temp;

	if (edge > stacks[0]->count)
	edge = stacks[0]->count;
	temp = edge;
	while (edge)
	{
		stacks[1]->count++;
		stacks[1]->index[stacks[1]->count - 1] 
			= stacks[0]->index[stacks[0]->count - 1];
		stacks[0]->count--;
		edge--;
	}
	bubblesort_b(temp, stacks);
}
