/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_subsequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:14:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/08 14:05:50 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*init_index(int edge)
{
	int	i;
	int	*index;

	index = malloc(sizeof(int) * edge);
	if (!index)
		ps_print_error();
	i = 0;
	while (i < edge)
	{
		index[i] = 1;
		i++;
	}
	return (index);
}

static int	*index_lds(t_stack *stack, int edge, int swap)
{
	int	*index;
	int	i;
	int	j;

	index = init_index(edge);
	i = 1;
	while (i < edge)
	{
		j = 0;
		while (j < i)
		{
			if (swap == 1 && stack->index[stack->count - 1 - i]
				< stack->index[stack->count - 1 - j]
				&& index[i] < index[j] + 1)
				index[i] = index[j] + 1;
			else if (swap == -1 && stack->index[i] < stack->index[j]
				&& index[i] < index[j] + 1)
				index[i] = index[j] + 1;
			j++;
		}
		i++;
	}
	return (index);
}

static int	get_max(int *index, int edge)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < edge)
	{
		if (max < index[i])
			max = index[i];
		i++;
	}
	return (max);
}

int	*ps_get_lds(t_stack *stack, int edge, int swap)
{
	int	*lds;
	int	*index;
	int	max;

	index = index_lds(stack, edge, swap);
	max = get_max(index, edge);
	lds = malloc(sizeof(int) * (max + 1));
	if (!lds)
		ps_print_error();
	lds[max] = -1;
	edge -= 1;
	while (edge >= 0)
	{
		if (index[edge] == max)
		{
			if (swap == 1)
				lds[max - 1] = stack->index[stack->count - 1 - edge];
			else
				lds[max - 1] = stack->index[edge];
			max--;
		}
		edge--;
	}
	free(index);
	return (lds);
}
