/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/16 22:23:55 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->index[i] > stack->index[i + 1] && i < stack->count - 1)
		i++;
	// printf("iterations: %i\n", i);
	// printf("index count: %zu\n", stack->count);
	if (i == stack->count - 1)
	{
		// printf("is sorted: 1\n\n");
		return (1);
	}
	// printf("is sorted: 0\n\n");
	return (0);
}

static int	is_substack_sorted(t_stack *stack)
{
	if (stack->index[stack->count - 1]
			< stack->index[stack->count - 2])
		return (1);
	return (0);
}

// static void	merge_stacks(t_stack **stacks, t_vector *vector)
// {
// 	while (stacks[1]->count)
// 	{
// 		if (stacks[1]->index[stacks[1]->count - 1]
// 			< stacks[0]->index[stacks[0]->count - 1])
// 		{
// 			operate(stacks, vector, 3);
// 			operate(stacks, vector, 5);
// 		}
// 		else
// 			operate(stacks, vector, 5);
// 	}
// 	operate(stacks, vector, 5);
// }

static int	split_substack(t_stack **stacks, t_vector *vector, int first, int last)
{
	int	pivot;
	int	i;

	pivot = (stacks[0]->index[0] + stacks[0]->index[stacks[0]->count - 1]
			+ stacks[0]->index[stacks[0]->count / 2]) / 3;
	i = stacks[0]->count - 1;
	while (i >= 0)
	{
		if (stacks[0]->index[stacks[0]->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else
			operate(stacks, vector, 5);
		i--;
		// sleep(1);
		// printf("\n\n");
		// printf("pivot: %i\n", pivot);
		// printf("first: %i\n", first);
		// printf("last: %i\n", last);
		// printf("i: %i\n", i);
		// print_stack(stacks[0]);
		// print_stack(stacks[1]);
	}
	// i = stacks[0]->count - 1;
	return (0);
}

static void	quicksort(t_stack **stacks, t_vector *vector, int first, int last)
{
	int	edge;

	if (stacks[0]->count > 0)
	{
		edge = split_substack(stacks, vector, first, last);
		last = stacks[0]->count - 1;
		quicksort(stacks, vector, edge, last);
	}
}

void	sort(t_stack **stacks, t_vector *vector)
{
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	quicksort(stacks, vector, 0, stacks[0]->count - 1);
	// merge_stacks(stacks, vector);
}
