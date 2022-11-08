/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:28 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/08 20:23:08 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_stacks(t_stack **stacks)
{
	free(stacks[0]->index);
	free(stacks[1]->index);
	free(stacks[0]);
	free(stacks[1]);
	free(stacks);
}

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

int	*arr_reverse(int *int_arr, int count)
{
	int	swap;
	int	i;

	i = 0;
	while (i < count / 2)
	{
		swap = int_arr[i];
		int_arr[i] = int_arr[count - 1 - i];
		int_arr[count - 1 - i] = swap;
		i++;
	}
	return (int_arr);
}

t_stack	**ps_init_stacks(char **input, int count)
{
	int		*int_arr;
	t_stack	**stacks;

	stacks = malloc(sizeof(t_stack *) * 2);
	if (!stacks)
		ps_print_error();
	stacks[0] = malloc(sizeof(t_stack));
	stacks[1] = malloc(sizeof(t_stack));
	if (!stacks[0] || !stacks[1])
		ps_print_error();
	stacks[0]->count = count;
	int_arr = str_arr_to_int_arr(input, stacks);
	stacks[0]->index = get_int_arr_index(int_arr, stacks[0]->count);
	stacks[1]->count = 0;
	stacks[1]->index = malloc(sizeof(int) * (stacks[0]->count));
	if (!stacks[1]->index)
		ps_print_error();
	free(int_arr);
	if (!stacks[0]->index)
	{
		ps_free_stacks(stacks);
		ps_print_error();
	}
	return (stacks);
}
