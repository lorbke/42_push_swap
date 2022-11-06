/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:48:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 00:31:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 2 1
void	case_one(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		operate(stacks, vector, 0);
		operate(stacks, vector, 5);
		operate(stacks, vector, 0);
		operate(stacks, vector, 8);
		operate(stacks, vector, 0);
	}
	else
	{
		operate(stacks, vector, 5);
		operate(stacks, vector, 0);
	}
}

// 2 3 1
void	case_two(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		operate(stacks, vector, 5);
		operate(stacks, vector, 0);
		operate(stacks, vector, 8);
		operate(stacks, vector, 0);
	}
	else
		operate(stacks, vector, 8);
}

// 3 1 2
void	case_three(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		operate(stacks, vector, 0);
		operate(stacks, vector, 5);
		operate(stacks, vector, 0);
		operate(stacks, vector, 8);
	}
	else
		operate(stacks, vector, 5);
}

// 1 3 2
void	case_four(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->count > 3)
	{
		operate(stacks, vector, 5);
		operate(stacks, vector, 0);
		operate(stacks, vector, 8);
	}
	else
	{
		operate(stacks, vector, 8);
		operate(stacks, vector, 0);
	}
}
