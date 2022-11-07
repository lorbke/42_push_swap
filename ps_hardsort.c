/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:18:43 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 16:05:35 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hardsort_three(int swap, t_stack **stacks, t_vector *vector)
{
	int	one;
	int	two;
	int	three;

	if (swap == -1)
	{
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 8);
	}
	one = stacks[0]->index[stacks[0]->count - 1];
	two = stacks[0]->index[stacks[0]->count - 2];
	three = stacks[0]->index[stacks[0]->count - 3];
	if (one > two && two > three)
		ps_case_one(stacks, vector);
	else if (one < two && two > three && one > three)
		ps_case_two(stacks, vector);
	else if (one > two && two < three && one > three)
		ps_case_three(stacks, vector);
	else if (one < two && two > three && one < three)
		ps_case_four(stacks, vector);
	else if (one > two && two < three && one < three)
		ps_operate(stacks, vector, 0);
}

void	ps_hardsort_two(int swap, t_stack **stacks, t_vector *vector)
{
	if (swap == -1 && stacks[0]->count > 2)
	{
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 8);
	}
	if (!ps_is_top_sorted(stacks[0]))
		ps_operate(stacks, vector, 0);
}

void	ps_hardsort(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	if (ps_is_stack_sorted(edge, swap, stacks[0]))
	{
		while (edge-- && swap == -1)
			ps_operate(stacks, vector, 8);
		return ;
	}
	if (edge == 2)
		ps_hardsort_two(swap, stacks, vector);
	else if (edge == 1 && swap == -1)
		ps_operate(stacks, vector, 8);
	else if (edge == 3)
		hardsort_three(swap, stacks, vector);
}
