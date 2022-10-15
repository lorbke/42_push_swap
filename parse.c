/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:33:42 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/15 16:13:14 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_int_position(int *int_arr, size_t count)
{
	int	highest_position;
	int	i;

	highest_position = 0;
	i = 0;
	while (i < count)
	{
		if (int_arr[i] > int_arr[highest_position])
			highest_position = i;
		i++;
	}
	return (highest_position);
}

static int	get_next_lower_position(int *int_arr, size_t count, int position)
{
	int	i;
	int	next_lower_position;

	i = 0;
	while (i < count)
	{
		if (int_arr[i] < int_arr[position])
		{
			next_lower_position = i;
			while (i < count)
			{
				if (int_arr[i] > int_arr[next_lower_position]
					&& int_arr[i] < int_arr[position])
						next_lower_position = i;
				i++;
			}
		}
		i++;
	}
	return (next_lower_position);
}

static int	*get_int_arr_index(int *int_arr, size_t count)
{
	int *arr_index;
	int	i;
	int	last_position;

	arr_index = malloc(sizeof(int) * count);
	last_position = get_highest_int_position(int_arr, count);
	i = count - 1;
	while (i >= 0)
	{
		arr_index[last_position] = i;
		last_position = get_next_lower_position(int_arr, count, last_position);
		i--;
	}
	return (arr_index);
}

static int	*str_arr_to_int_arr(char **str, size_t count)
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
