/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:07:15 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 16:03:40 by lorbke           ###   ########.fr       */
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

static void	operate_five(t_stack **stacks, t_vector *vector, int operation)
{
	if (operation == 8)
	{
		if (stacks[0]->count > 1)
		{
			ps_rotate_stack_down(stacks[0]);
			ft_vector_push_back_str(vector, "rra\n", 4);
		}
	}
	else if (operation == 2)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			ps_swap_top_of_stack(stacks[0]);
			ps_swap_top_of_stack(stacks[1]);
			ft_vector_push_back_str(vector, "ss\n", 3);
		}
	}
}

static void	operate_four(t_stack **stacks, t_vector *vector, int operation)
{
	if (operation == 9)
	{
		if (stacks[1]->count > 1)
		{
			ps_rotate_stack_down(stacks[1]);
			ft_vector_push_back_str(vector, "rrb\n", 4);
		}
	}
	else if (operation == 10)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			ps_rotate_stack_down(stacks[0]);
			ps_rotate_stack_down(stacks[1]);
			ft_vector_push_back_str(vector, "rrr\n", 4);
		}
	}
	operate_five(stacks, vector, operation);
}

static void	operate_three(t_stack **stacks, t_vector *vector, int operation)
{
	if (operation == 6)
	{
		if (stacks[1]->count > 1)
		{
			ps_rotate_stack_up(stacks[1]);
			ft_vector_push_back_str(vector, "rb\n", 3);
		}
	}
	else if (operation == 7)
	{
		if (stacks[0]->count > 1 && stacks[1]->count > 1)
		{
			ps_rotate_stack_up(stacks[0]);
			ps_rotate_stack_up(stacks[1]);
			ft_vector_push_back_str(vector, "rr\n", 3);
		}
	}
	operate_four(stacks, vector, operation);
}

static void	operate_two(t_stack **stacks, t_vector *vector, int operation)
{
	if (operation == 3)
	{
		if (stacks[1]->count > 0)
		{
			ps_push_to_stack(stacks[1], stacks[0]);
			ft_vector_push_back_str(vector, "pa\n", 3);
		}
	}
	else if (operation == 4)
	{
		if (stacks[0]->count > 0)
		{
			ps_push_to_stack(stacks[0], stacks[1]);
			ft_vector_push_back_str(vector, "pb\n", 3);
		}
	}
	else if (operation == 5)
	{
		if (stacks[0]->count > 1)
		{
			ps_rotate_stack_up(stacks[0]);
			ft_vector_push_back_str(vector, "ra\n", 3);
		}
	}
	operate_three(stacks, vector, operation);
}

void	ps_operate(t_stack **stacks, t_vector *vector, int operation)
{
	if (operation == 0)
	{
		if (stacks[0]->count > 1)
		{
			ps_swap_top_of_stack(stacks[0]);
			ft_vector_push_back_str(vector, "sa\n", 3);
		}
	}
	else if (operation == 1)
	{
		if (stacks[1]->count > 1)
		{
			ps_swap_top_of_stack(stacks[1]);
			ft_vector_push_back_str(vector, "sb\n", 3);
		}
	}
	operate_two(stacks, vector, operation);
}
