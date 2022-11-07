/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:01:01 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/07 23:44:35 by lorbke           ###   ########.fr       */
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

	if (int_arr == NULL)
		return (NULL);
	arr_index = malloc(sizeof(int) * count);
	if (!arr_index)
		return (NULL);
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

static int	*arr_reverse(int *int_arr, int count)
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

int	*str_arr_to_int_arr(char **str, t_stack **stacks)
{
	int			*int_arr;
	int			i;
	int			j;
	int			temp_size;
	const char	*endptr;

	int_arr = malloc(sizeof(int) * stacks[0]->count);
	if (!int_arr)
		return (NULL);
	i = 0;
	j = 0;
	temp_size = stacks[0]->count;
	while (i < stacks[0]->count)
	{
		endptr = str[i];
		while (*endptr)
		{
			if (j >= temp_size)
			{
				int_arr = ft_realloc_ftprintf
					(int_arr, temp_size * 4 * 8, temp_size * 8);
				if (!int_arr)
					return (NULL);
				temp_size *= 4;
			}
			int_arr[j] = ft_strtoi(endptr, &endptr, 10);
			if (int_arr[j] == 0 && errno == EINVAL)
				break ;
			if (errno == ERANGE || errno == EINVAL)
				return (NULL);
			j++;
		}
		i++;
	}
	stacks[0]->count = j;
	return (arr_reverse(int_arr, j));
}
