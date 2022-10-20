/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:33:29 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 15:17:26 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* OPERATIONS 
	00 = sa
	01 = sb
	02 = ss
	03 = pa
	04 = pb
	05 = ra
	06 = rb
	07 = rr
	08 = rra
	09 = rrb
	10 = rrr
*/

void	path_operate(t_stack **stacks, t_intvec *vec, t_vector *vector)
{
	int	i;

	i = 0;
	while (i < vec->count)
	{
		operate(stacks, vector, vec->array[i]);
		i++;
	}
}

void	reverse_operate(t_stack **stacks, t_intvec *vec, int operation)
{
	if (operation == 0)
	{
			if (!test_operate(stacks, vec, 0))
				return ;
	}
	else if (operation == 1)
	{
			if (!test_operate(stacks, vec, 1))
				return ;
	}
	else if (operation == 2)
	{
			if (!test_operate(stacks, vec, 2))
				return ;
	}
	else if (operation == 3)
	{
			if (!test_operate(stacks, vec, 4))
				return ;
	}
	else if (operation == 4)
	{
			if (!test_operate(stacks, vec, 3))
				return ;
	}
	else if (operation == 5)
	{
			if (!test_operate(stacks, vec, 8))
				return ;
	}
	else if (operation == 6)
	{
			if (!test_operate(stacks, vec, 9))
				return ;
	}
	else if (operation == 7)
	{
			if (!test_operate(stacks, vec, 10))
				return ;
	}
	else if (operation == 8)
	{
			if (!test_operate(stacks, vec, 5))
				return ;
	}
	else if (operation == 9)
	{
			if (!test_operate(stacks, vec, 6))
				return ;
	}
	else if (operation == 10)
	{
			if (!test_operate(stacks, vec, 7))
				return ;
	}
	else
		return ;
	vec->count -= 2;
}
