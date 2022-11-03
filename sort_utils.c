/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/21 01:46:31 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(int edge, int swap, t_stack *stack)
{
	int	i;

	i = 0;
	if (swap == 1)
	{
		while (stack->index[stack->count - 1 - i]
			< stack->index[stack->count - 2 - i] && i < edge - 1)
			i++;
	}
	else
	{
		while (stack->index[i] > stack->index[i + 1] && i < edge - 1)
			i++;
	}
	if (i == edge - 1)
		return (1);
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

void	sort(t_stack **stacks, t_vector *vector)
{
	// while (stacks[0]->count)
	// {
	// 	operate(stacks, vector, 4);
	// }
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	quicksort_a(stacks[0], stacks[0]->count, 1, stacks, vector);
	// hardsort(3, 1, stacks, vector);
	// printf("\n\n");
	// printf("\n\n");
	// int	i = 0;
	// while (i < 50)
	// {
	// 	operate(stacks, vector, 4);
	// 	i++;
	// }
	// printf("\n");
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	// printf("\n");
	// insertionsort(50, 1, stacks, vector);
	// printf("\n");
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
}
