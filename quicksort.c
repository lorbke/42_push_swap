/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:26:51 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/18 22:13:57 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_stack_b(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;
	int	rotations;

	pivot = (current->index[current->count - 1]
			+ current->index[current->count - (edge / 2 + 1)]
			+ current->index[current->count - edge]) / 3;
	temp = current->count - 1;
	i = current->count - edge;
	rotations = 0;
	while (i <= temp)
	{
		// printf("pivot: %i\n", pivot);
		// print_stack(stacks[0]);
		// print_stack(stacks[1]);
		// printf("\n\n");
		// sleep(1);
		if (current->index[current->count - 1] >= pivot)
			operate(stacks, vector, 3);
		else
		{
			operate(stacks, vector, 6);
			rotations++;
		}
		i++;
	}
	while (rotations)
	{
		operate(stacks, vector, 9);
		rotations--;
	}
	return (temp + 1 - current->count);
}

static void	quicksort_b(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 0)
	{
		new_edge = split_stack_b(current, edge, stacks, vector);
		quicksort_a(stacks[0], new_edge, stacks, vector);
		quicksort_b(current, edge - new_edge, stacks, vector);
	}
	// else if (edge == 2)
	// {
	// 	if (is_substack_sorted(current))
	// 		operate(stacks, vector, 1);
	// 	// operate(stacks, vector, 3);
	// 	// operate(stacks, vector, 3);
	// }
	// else
	// 	operate(stacks, vector, 3);
}

static int	split_stack_a(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;
	int rotations;

	pivot = (current->index[current->count - 1]
			+ current->index[current->count - edge / 2]
			+ current->index[current->count - edge]) / 3;
	temp = current->count - 1;
	i = current->count - edge;
	rotations = 0;
	while (i <= temp)
	{
		// printf("pivot: %i\n", pivot);
		// print_stack(stacks[0]);
		// print_stack(stacks[1]);
		// printf("\n\n");
		// sleep(1);
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else
		{
			operate(stacks, vector, 5);
			rotations++;
		}
		i++;
	}
	while (rotations)
	{
		operate(stacks, vector, 8);
		rotations--;
	}
	return (temp + 1 - current->count);
}

void	quicksort_a(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (edge > 1)
	{
		new_edge = split_stack_a(current, edge, stacks, vector);
		quicksort_a(current, edge - new_edge, stacks, vector);
		quicksort_b(stacks[1], new_edge, stacks, vector);
	}
	// else if (edge == 2)
	// {
	// 	if (!is_substack_sorted(current))
	// 		operate(stacks, vector, 0);
	// 	// operate(stacks, vector, 4);
	// 	// operate(stacks, vector, 4);
	// }
	// else
	// 	operate(stacks, vector, 4);
}


static int	split_stack_start(t_stack *current, int subedge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = (current->index[current->count - 1]
			+ current->index[(current->count / 2) / 2]
			+ current->index[0]) / 3;
	temp = current->count - 1;
	i = 0;
	while (i <= temp)
	{
				printf("pivot: %i\n", pivot);
		// print_stack(stacks[0]);
		// print_stack(stacks[1]);
		// printf("\n\n");
		// sleep(1);
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else
			operate(stacks, vector, 5);
		i++;
	}
	return (temp + 1 - current->count);
}

void	quicksort_start(t_stack *current, int edge, t_stack **stacks, t_vector *vector)
{
	int	new_edge;

	if (current->count > 0)
	{
		new_edge = split_stack_start(current, edge, stacks, vector);
		quicksort_start(current, edge, stacks, vector);
		quicksort_b(stacks[1], new_edge, stacks, vector);
	}
}
