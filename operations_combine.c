/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/15 13:16:00 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printing solution is unstructured, edge case of operation not working not handled

#include "push_swap.h"

int	swap_top_of_both_stacks(t_stack **stacks, t_vector *vector)
{
	if (swap_top_of_stack(stacks[0], vector) 
		&& swap_top_of_stack(stacks[1], vector) == 1)
			return (1);
	return (0);
}

int	rotate_both_stacks_up(t_stack **stacks, t_vector *vector)
{
	rotate_stack_up(stacks[0], vector);
	rotate_stack_up(stacks[1], vector);
}

int	rotate_both_stacks_down(t_stack **stacks, t_vector *vector)
{
	rotate_stack_down(stacks[0], vector);
	rotate_stack_down(stacks[1], vector);
}
