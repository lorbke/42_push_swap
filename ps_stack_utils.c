/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:28 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/07 23:45:45 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *dst, int *src, int n)
{
	int	i;

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

t_stack	**ps_init_stacks(t_stack **stacks, char **input, int count)
{
	int	*int_arr;

	stacks = malloc(sizeof(t_stack *) * 2);
	if (!stacks)
		return (NULL);
	stacks[0] = malloc(sizeof(t_stack));
	if (!stacks[0])
		return (NULL);
	stacks[1] = malloc(sizeof(t_stack));
	if (!stacks[1])
		return (NULL);
	stacks[0]->id = 'a';
	stacks[1]->id = 'b';
	stacks[0]->count = count;
	int_arr = str_arr_to_int_arr(input, stacks);
	if (!int_arr)
		return (NULL);
	stacks[0]->index = get_int_arr_index(int_arr, stacks[0]->count);
	if (!stacks[0]->index)
		return (NULL);
	stacks[0]->index[stacks[0]->count] = -1;
	stacks[1]->count = 0;
	stacks[1]->index = malloc(sizeof(int) * (stacks[0]->count + 1));
	if (!stacks[1]->index)
		return (NULL);
	return (stacks);
}
