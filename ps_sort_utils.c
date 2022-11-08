/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/08 19:17:37 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_stack_sorted(int edge, int swap, t_stack *stack)
{
	int	i;

	i = 0;
	if (swap == 1)
	{
		while (i < edge - 1 && stack->index[stack->count - 1 - i]
			< stack->index[stack->count - 2 - i])
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

int	ps_is_top_sorted(t_stack *stack)
{
	if (stack->index[stack->count - 1]
		< stack->index[stack->count - 2])
		return (1);
	return (0);
}

int	ps_get_highest(t_stack *stack)
{
	int	highest;
	int	i;

	highest = 0;
	i = 0;
	while (i < stack->count)
	{
		if (stack->index[i] > highest)
			highest = stack->index[i];
		i++;
	}
	return (highest);
}
