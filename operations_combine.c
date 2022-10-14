/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 22:16:05 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printing solution is unstructured, edge case of operation not working not handled

#include "push_swap.h"

void	swap_top_of_both_stacks(t_stack **stacks, t_vector *vector)
{
	swap_top_of_stack(stacks[0], vector, 1);
	swap_top_of_stack(stacks[1], vector, 1);
	ft_vector_push_back(vector, '\n', 1);
}

void	rotate_both_stacks_up(t_stack **stacks, t_vector *vector)
{
	rotate_stack_up(stacks[0], vector, 1);
	rotate_stack_up(stacks[1], vector, 1);
	ft_vector_push_back(vector, 'r', 1);
	ft_vector_push_back(vector, '\n', 1);
}

void	rotate_both_stacks_down(t_stack **stacks, t_vector *vector)
{
	rotate_stack_down(stacks[0], vector, 1);
	rotate_stack_down(stacks[1], vector, 1);
}
