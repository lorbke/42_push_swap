/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:01:01 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 01:42:44 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_int_position(int *int_arr, int count)
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

static int	get_next_lower_position(int *int_arr, int count, int position)
{
	int	i;
	int	next_lower_position;

	i = 0;
	while (i < count)
	{
		if (i != position && int_arr[i] == int_arr[position])
			return (-1);
		if (int_arr[i] < int_arr[position])
		{
			next_lower_position = i;
			while (i < count)
			{
				if (i != position && int_arr[i] == int_arr[position])
					return (-1);
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

int	*get_int_arr_index(int *int_arr, int count)
{
	int	*arr_index;
	int	i;
	int	last_position;

	arr_index = malloc(sizeof(int) * count);
	last_position = get_highest_int_position(int_arr, count);
	i = count - 1;
	while (i >= 0)
	{
		arr_index[last_position] = i;
		last_position = get_next_lower_position(int_arr, count, last_position);
		if (last_position == -1)
			return (NULL);
		i--;
	}
	return (arr_index);
}

int	*str_arr_to_int_arr(char **str, int count)
{
	int	*int_arr;
	int	i;

	int_arr = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		int_arr[i] = ft_atoi(str[count - 1 - i]);
		i++;
	}
	return (int_arr);
}
