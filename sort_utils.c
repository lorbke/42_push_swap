/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 16:39:37 by lorbke           ###   ########.fr       */
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

static int	get_largest(t_stack *stack, int edge)
{
	int	highest_value;
	int	i;

	highest_value = 0;
	i = stack->count - 1;
	while (i >= 0)
	{
		if (highest_value < stack->index[i])
			highest_value = stack->index[i];
		i--;
	}
	return (highest_value);
}

// void	merge_stacks(int edge, t_stack **stacks, t_vector *vector)
// {
// 	while (stacks[1]->count)
// 	{
// 		move_to_largest(stacks[1], stacks[1]->count, stacks, vector);
// 		if (stacks[1]->index[stacks[1]->count - 1]
// 			== stacks[0]->index[stacks[0]->count - 1] - 1)
// 		{
// 			operate(stacks, vector, 3);
// 		}
// 		// print_stack(stacks[0]);
// 		// print_stack(stacks[1]);
// 		// printf("\n\n");
// 		// sleep(1);
// 	}
// }

void	sort(t_stack **stacks, t_vector *vector)
{
	// while (stacks[0]->count)
	// {
	// 	operate(stacks, vector, 4);
	// }
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	quicksort_a(stacks[0], stacks[0]->count, 1, stacks, vector);
	// printf("\n\n");
	// printf("\n\n");
	// operate(stacks, vector, 4);
	// operate(stacks, vector, 4);
	// operate(stacks, vector, 4);
	// operate(stacks, vector, 4);
	// operate(stacks, vector, 4);
}
