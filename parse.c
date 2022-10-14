/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:33:42 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 18:21:23 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_int_arr_index(int *int_arr, size_t count)
{
	int	*arr_index;
	int	i;

	arr_index = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		arr_index[i] = count - i;
		i++;
	}
	return (arr_index);
}

int	*str_arr_to_int_arr(char **str, size_t count)
{
	int	*int_arr;
	int	i;

	int_arr = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		int_arr[i] = ft_atoi(str[i]);
		i++;
	}
	return (int_arr);
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
