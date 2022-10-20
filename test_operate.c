/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:40:58 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 00:50:45 by lorbke           ###   ########.fr       */
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
void	test_operate(t_stack **stacks, t_intvec *vec, int operation)
{
	if (operation == 0)
	{
		if (stacks[0]->count > 1)
		{
			swap_top_of_stack(stacks[0]);
			intvec_push_back(vec, 0);
		}
	}
	else if (operation == 1)
	{
		if (stacks[1]->count > 1)
		{
			swap_top_of_stack(stacks[1]);
			intvec_push_back(vec, 1);
		}
	}
	else if (operation == 2)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			swap_top_of_stack(stacks[0]);
			swap_top_of_stack(stacks[1]);
			intvec_push_back(vec, 2);
		}
	}
	else if (operation == 3)
	{
		if (stacks[1]->count > 0)
		{
			push_to_stack(stacks[1], stacks[0]);
			intvec_push_back(vec, 3);
		}
	}
	else if (operation == 4)
	{
		if (stacks[0]->count > 0)
		{
			push_to_stack(stacks[0], stacks[1]);
			intvec_push_back(vec, 4);
		}
	}
	else if (operation == 5)
	{
		if (stacks[0]->count > 1)
		{
			rotate_stack_up(stacks[0]);
			intvec_push_back(vec, 5);
		}
	}
	else if (operation == 6)
	{
		if (stacks[1]->count > 1)
		{
			rotate_stack_up(stacks[1]);
			intvec_push_back(vec, 6);
		}
	}
	else if (operation == 7)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			rotate_stack_up(stacks[0]);
			rotate_stack_up(stacks[1]);
			intvec_push_back(vec, 7);
		}
	}	
	else if (operation == 8)
	{
		if (stacks[0]->count > 1)
		{
			rotate_stack_down(stacks[0]);
			intvec_push_back(vec, 8);
		}
	}
	else if (operation == 9)
	{
		if (stacks[1]->count > 1)
		{
			rotate_stack_down(stacks[1]);
			intvec_push_back(vec, 9);
		}
	}
	else if (operation == 10)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			rotate_stack_down(stacks[0]);
			rotate_stack_down(stacks[1]);
			intvec_push_back(vec, 10);
		}
	}
}
