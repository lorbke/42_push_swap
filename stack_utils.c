/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:28 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 01:21:38 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *dst, int *src, size_t n)
{
	size_t	i;
	size_t	len;

	if (n == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

t_stack	**init_stacks(t_stack **stacks, char **input, size_t count)
{
	stacks = malloc(sizeof(t_stack *) * 2);
	stacks[0] = malloc(sizeof(t_stack));
	stacks[1] = malloc(sizeof(t_stack));
	stacks[0]->id = 'a';
	stacks[1]->id = 'b';
	stacks[0]->count = count;
	stacks[0]->index
		= get_int_arr_index(str_arr_to_int_arr
			(input, stacks[0]->count), stacks[0]->count);
	stacks[0]->index[count] = -1;
	stacks[1]->count = 0;
	stacks[1]->index = malloc(sizeof(int) * (count + 1));
	// int	i = 0;
	// while (i < count)
	// {
	// 	printf("%i", stacks[0]->index[i]);
	// 	printf("%i", stacks[0]->index[i]);
	// 	i++;
	// }
	return (stacks);
}

t_stack	*copy_stack(t_stack *stack_copy, t_stack *stack)
{
	stack_copy = malloc(sizeof(t_stack));
	stack_copy->id = stack->id + 2;
	stack_copy->count = stack->count;
	stack_copy->index = malloc(sizeof(int)
		* (stack->count));
	stack_copy->index = copy_array(stack_copy->index,
			stack->index, stack->count);
	return (stack_copy);
}
