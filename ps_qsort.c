/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:26:51 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 16:03:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack *current, int edge, int swap)
{
	int	pivot;
	int	i;

	pivot = 0;
	i = 0;
	if (swap == -1)
	{
		while (i < edge)
			pivot += current->index[i++];
	}
	else
	{
		while (i < edge)
			pivot += current->index[current->count - 1 - i++];
	}
	return (pivot /= i);
}

static int
	split_stack_b(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = get_pivot(stacks[1], edge, swap);
	temp = stacks[1]->count - 1;
	i = stacks[1]->count - edge;
	while (i <= temp)
	{
		if (swap == -1)
			ps_operate(stacks, vector, 9);
		if (stacks[1]->index[stacks[1]->count - 1] > pivot)
			ps_operate(stacks, vector, 3);
		else if (swap == 1)
			ps_operate(stacks, vector, 6);
		i++;
	}
	return (temp + 1 - stacks[1]->count);
}

static void	ps_qsort_b(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 25)
	{
		new_edge = split_stack_b(edge, swap, stacks, vector);
		ps_qsort_a(new_edge, 1, stacks, vector);
		ps_qsort_b(edge - new_edge, swap * -1, stacks, vector);
	}
	else
		ps_insort(edge, swap, stacks, vector);
}

static int
	split_stack_a(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = get_pivot(stacks[0], edge, swap);
	temp = stacks[0]->count - 1;
	i = stacks[0]->count - edge;
	while (i <= temp)
	{
		if (swap == -1)
			ps_operate(stacks, vector, 8);
		if (stacks[0]->index[stacks[0]->count - 1] <= pivot)
			ps_operate(stacks, vector, 4);
		else if (swap == 1)
		{
			ps_operate(stacks, vector, 5);
		}
		i++;
	}
	return (temp + 1 - stacks[0]->count);
}

void	ps_qsort_a(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 3)
	{
		new_edge = split_stack_a(edge, swap, stacks, vector);
		ps_qsort_a(edge - new_edge, swap * -1, stacks, vector);
		ps_qsort_b(new_edge, 1, stacks, vector);
	}
	else
		ps_hardsort(edge, swap, stacks, vector);
}
