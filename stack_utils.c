/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:28 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/19 21:40:17 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_array(int *dst, int *src, size_t n)
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
	stacks[1]->count = 0;
	stacks[1]->index = malloc(sizeof(int) * count);
	// int	i = 0;
	// while (i < count)
	// {
	// 	printf("%i", stacks[0]->index[i]);
	// 	printf("%i", stacks[0]->index[i]);
	// 	i++;
	// }
	return (stacks);
}

t_stack	**copy_stacks(t_stack **stacks_copy, t_stack **stacks)
{
	stacks_copy = malloc(sizeof(t_stack *) * 2);
	stacks_copy[0] = malloc(sizeof(t_stack));
	stacks_copy[1] = malloc(sizeof(t_stack));
	stacks_copy[0]->id = 'c';
	stacks_copy[1]->id = 'd';
	stacks_copy[0]->count = stacks[0]->count;
	stacks_copy[1]->count = stacks[1]->count;
	stacks_copy[0]->index = malloc(sizeof(int)
			* (stacks[0]->count + stacks[1]->count));
	stacks_copy[0]->index = copy_array(stacks_copy[0]->index,
			stacks[0]->index, stacks[0]->count);
	stacks_copy[1]->index = malloc(sizeof(int)
			* (stacks[1]->count + stacks[1]->count));
	stacks_copy[1]->index = copy_array(stacks_copy[1]->index,
			stacks[1]->index, stacks[1]->count);
	return (stacks_copy);
}
