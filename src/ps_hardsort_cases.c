/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardsort_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:48:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/09 21:05:42 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

// 3 2 1
void	ps_case_one(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 5);
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 0);
	}
	else
	{
		ps_operate(stacks, vector, 5);
		ps_operate(stacks, vector, 0);
	}
}

// 2 3 1
void	ps_case_two(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		ps_operate(stacks, vector, 5);
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 0);
	}
	else
		ps_operate(stacks, vector, 8);
}

// 3 1 2
void	ps_case_three(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 5);
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 8);
	}
	else
		ps_operate(stacks, vector, 5);
}

// 1 3 2
void	ps_case_four(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		ps_operate(stacks, vector, 5);
		ps_operate(stacks, vector, 0);
		ps_operate(stacks, vector, 8);
	}
	else
	{
		ps_operate(stacks, vector, 8);
		ps_operate(stacks, vector, 0);
	}
}
