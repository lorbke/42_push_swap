/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/18 19:31:13 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
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

int	is_substack_sorted(t_stack *stack)
{
	if (stack->index[stack->count - 1]
			< stack->index[stack->count - 2])
		return (1);
	return (0);
}

void	merge_stacks(t_stack **stacks, t_vector *vector)
{
	while (stacks[1]->count)
	{
		if (stacks[1]->index[stacks[1]->count - 1]
			< stacks[0]->index[stacks[0]->count - 1])
		{
			operate(stacks, vector, 3);
		}
		else
			operate(stacks, vector, 5);
	}
}

void	sort(t_stack **stacks, t_vector *vector)
{
	// while (stacks[0]->count)
	// {
	// 	operate(stacks, vector, 4);
	// }
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	// move_to_highest(stacks[1], stacks, vector, 40);
	// bubblesort(stacks[1], 40, stacks, vector);
	quicksort_start(stacks[0], 0, stacks, vector);
	// merge_stacks(stacks, vector);
}
