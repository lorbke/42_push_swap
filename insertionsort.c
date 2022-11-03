/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:21:38 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 23:27:26 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_insert_pos(int insert, int max, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->index[i] > insert && stack->index[i + 1] == max)
			return (stack->index[i]);
		if (stack->index[i] > insert
			&& stack->index[i + 1] < insert)
			return (stack->index[i]);
		i++;
			// write(1, "2", 1);
	}
	return (stack->index[stack->count - 1]);
}

static int	get_direction(int number, t_stack *stack)
{
	int	top;
	int	bottom;
	int	temp;

	if (stack->index[stack->count - 1] == number)
		return (0);
	top = 0;
	bottom = 0;
	while (stack->index[stack->count - 1 - top] != number)
	{
		// write(1, "3", 1);
		top++;
	}
	while (stack->index[0 + bottom] != number)
	{
		// write(1, "4", 1);
		bottom++;
	}
	if (bottom - top == 0)
		return (bottom + 1 - top);
	return (bottom - top);
}

static void	rotate_direction(int direction_a, int direction_b, t_stack **stacks, t_vector *vector)
{
	if (direction_a < 0 && direction_b < 0)
		operate(stacks, vector, 10);
	else if (direction_a > 0 && direction_b > 0)
		operate(stacks, vector, 7);
	else if (direction_a < 0 && direction_b > 0)
	{
		operate(stacks, vector, 8);
		operate(stacks, vector, 6);
	}
	else if (direction_a > 0 && direction_b < 0)
	{
		operate(stacks, vector, 5);
		operate(stacks, vector, 9);
	}
	else if (direction_a < 0 && direction_b == 0)
		operate(stacks, vector, 8);
	else if (direction_a > 0 && direction_b == 0)
		operate(stacks, vector, 5);
	else if (direction_a == 0 && direction_b > 0)
		operate(stacks, vector, 6);
	else if (direction_a == 0 && direction_b < 0)
		operate(stacks, vector, 9);
}

static int	get_index_count(int *index, int edge)
{
	int	count;

	count = 0;
	while (edge)
	{
		if (index[edge - 1] > 0)
			count++;
		edge--;
		// write(1, "5", 1);
	}
	return (count);
}


static int	*get_lis(t_stack *stack, int *index, int edge, int swap)
{
	int	*lis;
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 1;
	while (i < edge)
	{
		if (index[i] > 0)
		{
			j = 0;
			while (j < i)
			{
				if (swap == 1 && stack->index[stack->count - 1 - i] > stack->index[stack->count - 1 - j]
					&& index[i] < index[j] + 1)
					index[i] = index[j] + 1;
				else if (swap == -1 && stack->index[i] > stack->index[j]
					&& index[i] < index[j] + 1)
					index[i] = index[j] + 1;
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (i < edge)
	{
		if (max < index[i])
			max = index[i];
		i++;
	}
	i--;
	j = 0;
	// printf("\n max:%i", max);
	// printf("\n index:");
	// while (j < edge)
	// {
	// 	printf("%i ", index[j]);
	// 	j++;
	// }
	// printf("\n");
	j = max;
	lis = malloc(sizeof(int) * (max + 1));
	lis[max] = -1;
	while (i >= 0)
	{
		if (index[i] == j)
		{
			index[i] = (edge + 1) * -1;
			if (swap == 1)
				lis[j - 1] = stack->index[stack->count - 1 - i];
			else 
				lis[j - 1] = stack->index[i];
			j--;
		}
		i--;
	}
	// printf("\n lds:");
	// i = 0;
	// while (lds[i] != -1)
	// {
	// 	printf("%i ", lds[i]);
	// 	i++;
	// }
	// printf("\n");
	return (lis);
}


static int	*get_lds(t_stack *stack, int *index, int edge, int swap)
{
	int	*lds;
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 1;
	while (i < edge)
	{
		if (index[i] > 0)
		{
			j = 0;
			while (j < i)
			{
				if (swap == 1 && stack->index[stack->count - 1 - i] < stack->index[stack->count - 1 - j]
					&& index[i] < index[j] + 1)
					index[i] = index[j] + 1;
				else if (swap == -1 && stack->index[i] < stack->index[j]
					&& index[i] < index[j] + 1)
					index[i] = index[j] + 1;
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (i < edge)
	{
		if (max < index[i])
			max = index[i];
		i++;
	}
	i--;
	j = 0;
	// printf("\n max:%i", max);
	// printf("\n index:");
	// while (j < edge)
	// {
	// 	printf("%i ", index[j]);
	// 	j++;
	// }
	// printf("\n");
	j = max;
	lds = malloc(sizeof(int) * (max + 1));
	lds[max] = -1;
	while (i >= 0)
	{
		if (index[i] == j)
		{
			index[i] = (edge + 1) * -1;
			if (swap == 1)
				lds[j - 1] = stack->index[stack->count - 1 - i];
			else 
				lds[j - 1] = stack->index[i];
			j--;
		}
		i--;
	}
	// printf("\n lds:");
	// i = 0;
	// while (lds[i] != -1)
	// {
	// 	printf("%i ", lds[i]);
	// 	i++;
	// }
	// printf("\n");
	return (lds);
}

static void	init_index(int *index, int edge)
{
	int	i;

	i = 0;
	while (i < edge)
	{
		if (index[i] > 0)
			index[i] = 1;
		i++;
	}
}

static int	get_highest(t_stack *stack)
{
	int	highest;
	int	i;

	highest = 0;
	i = 0;
	while (i < stack->count)
	{
		if (stack->index[i] > highest)
			highest = stack->index[i];
		i++;
	}
	return (highest);
}

static int	**get_sequences(t_stack *stack, int edge, int swap)
{
	int	**sequences;
	int	*index;
	int	i;
	int	temp;

	index = malloc(sizeof(int) * edge);
	i = 0;
	sequences = malloc(sizeof(int *) * 2);
	while (i < edge)
	{
		index[i] = 1;
		i++;
	}
	sequences[0] = get_lds(stack, index, edge, swap);
	sequences[1] = NULL;
	return (sequences);
}

// void	insertionsort(int edge, int swap, t_stack **stacks, t_vector *vector)
// {
// 	int	**sequences;
// 	int	max;
// 	int	temp;
// 	int	position;
// 	int	direction_a;
// 	int	direction_b;
// 	int	i;
// 	int	j;
// 	// temp = 100;
// 	// position = get_insert_pos(temp, stacks[0]);
// 	// printf("position: %i\n", position);
// 	// 	// max = 62;
// // 	// temp = 7;
// // 	// position = get_insert_pos(temp, max, stacks[0]);
// // 	// direction_a = get_direction(position, stacks[0]);
// // 	// direction_b = get_direction(temp, stacks[1]);
// // 	// printf("position: %i\n", position);
// // 	// printf("direction a: %i\n", direction_a);
// // 	// printf("direction b: %i\n", direction_b);
// // 	// while (stacks[1]->index[stacks[1]->count - 1] != temp
// // 	// 	|| stacks[0]->index[stacks[0]->count - 1] != position)
// // 	// 	rotate_direction(direction_a, direction_b, stacks, vector);
// 	sequences = get_sequences(stacks[1], edge, swap);
// 	i = 0;
// 	j = 0;
// 	while (sequences[i])
// 	{
// 		j = 0;
// 		printf("\n sequence:");
// 		while (sequences[i][j] != -1)
// 		{
// 			printf("%i ", sequences[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	insertionsort(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	**sequences;
	int	max;
	int	position;
	int	direction_a;
	int	direction_b;
	int	i;
	int	j;

	sequences = get_sequences(stacks[1], edge, swap);
	max = stacks[0]->index[0];
	i = 0;
	while (sequences[i] && edge > 4)
	{
		j = 0;
		while (sequences[i][j] != -1)
		{
			position = get_insert_pos(sequences[i][j], max, stacks[0]);
			direction_a = get_direction(position, stacks[0]);
			direction_b = get_direction(sequences[i][j], stacks[1]);
			while (stacks[0]->index[stacks[0]->count - 1] != position
				|| stacks[1]->index[stacks[1]->count - 1] != sequences[i][j])
			{
				if (stacks[0]->index[stacks[0]->count - 1] == position)
					direction_a = 0;
				if (stacks[1]->index[stacks[1]->count - 1] == sequences[i][j])
					direction_b = 0;
				rotate_direction(direction_a, direction_b, stacks, vector);
			}
			operate(stacks, vector, 3);
			edge--;
			j++;
		}
		i++;
	}
	while (edge)
	{
		position = get_insert_pos(get_highest(stacks[1]), max, stacks[0]);
		direction_a = get_direction(position, stacks[0]);
		direction_b = get_direction(get_highest(stacks[1]), stacks[1]);
		while (stacks[0]->index[stacks[0]->count - 1] != position
			|| stacks[1]->index[stacks[1]->count - 1] != get_highest(stacks[1]))
		{
			if (stacks[0]->index[stacks[0]->count - 1] == position)
				direction_a = 0;
			if (stacks[1]->index[stacks[1]->count - 1] == get_highest(stacks[1]))
				direction_b = 0;
			rotate_direction(direction_a, direction_b, stacks, vector);
		}
		operate(stacks, vector, 3);
		edge--;
	}
	direction_a = get_direction(max, stacks[0]);
	while (stacks[0]->index[0] != max)
	{
		rotate_direction(direction_a, 0, stacks, vector);
	}
}
