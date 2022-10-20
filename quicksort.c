/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:26:51 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 23:49:00 by lorbke           ###   ########.fr       */
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
		while (edge)
		{
			pivot += current->index[i];
			i++;
			edge--;
		}
	}
	else
	{
		while (edge)
		{
			pivot += current->index[current->count - 1 - i];
			i++;
			edge--;
		}
	}
	return (pivot /= i);
}

static int	split_stack_b(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = get_pivot(current, edge, swap);
	temp = current->count - 1;
	i = current->count - edge;
	while (i <= temp)
	{
		if (swap == -1)
			operate(stacks, vector, 9);
		if (current->index[current->count - 1] >= pivot)
			operate(stacks, vector, 3);
		else if (swap == 1)
			operate(stacks, vector, 6);
		i++;
	}
	return (temp + 1 - current->count);
}

static void	quicksort_b(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 10)
	{
		new_edge = split_stack_b(current, edge, swap, stacks, vector);
		quicksort_a(stacks[0], new_edge, 1, stacks, vector);
		quicksort_b(current, edge - new_edge, swap * -1, stacks, vector);
	}
	else
		insertionsort(edge, swap, stacks, vector);
	// else if (edge == 2)
	// {
	// 	if (swap == -1)
	// 	{
	// 		operate(stacks, vector, 9);
	// 		operate(stacks, vector, 9);
	// 	}
	// 	if (is_substack_sorted(stacks[1]))
	// 		operate(stacks, vector, 1);
	// 	operate(stacks, vector, 3);
	// 	operate(stacks, vector, 3);
	// }
	// else if (edge == 1)
	// {
	// 	if (swap == -1)
	// 		operate(stacks, vector, 9);
	// 	operate(stacks, vector, 3);
	// }
}

static int	split_stack_a(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = get_pivot(current, edge, swap);
	temp = current->count - 1;
	i = current->count - edge;
	while (i <= temp)
	{
		if (swap == -1)
			operate(stacks, vector, 8);
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else if (swap == 1)
		{
			operate(stacks, vector, 5);
		}
		i++;
	}
	return (temp + 1 - current->count);
}

void	quicksort_a(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 2)
	{
		new_edge = split_stack_a(current, edge, swap, stacks, vector);
		quicksort_a(current, edge - new_edge, swap * -1, stacks, vector);
		quicksort_b(stacks[1], new_edge, 1, stacks, vector);
	}
	else if (edge == 2)
	{
		if (swap == -1 && stacks[0]->count > 2)
		{
			operate(stacks, vector, 8);
			operate(stacks, vector, 8);
		}
		if (!is_substack_sorted(stacks[0]))
			operate(stacks, vector, 0);
	}
	else if (edge == 1 && swap == -1)
		operate(stacks, vector, 8);
}
