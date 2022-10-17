/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/18 00:18:33 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_stack_a(t_stack *current, int subedge, t_stack **stacks, t_vector *vector);
static int	split_stack_b(t_stack *current, int subedge, t_stack **stacks, t_vector *vector);
static int	split_stack_start(t_stack *current, int subedge, t_stack **stacks, t_vector *vector);
static void	quicksort_a(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector);
static void	quicksort_b(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector);
static void	quicksort_start(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector);

static int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->index[i] > stack->index[i + 1] && i < stack->count - 1)
		i++;
	// printf("iterations: %i\n", i);
	// printf("index count: %zu\n", stack->count);
	if (i == stack->count - 1)
	{
		// printf("is sorted: 1\n\n");
		return (1);
	}
	// printf("is sorted: 0\n\n");
	return (0);
}

static int	is_substack_sorted(t_stack *stack)
{
	if (stack->index[stack->count - 1]
			< stack->index[stack->count - 2])
		return (1);
	return (0);
}

static void	merge_stacks(t_stack **stacks, t_vector *vector)
{
	while (stacks[1]->count)
	{
		if (stacks[1]->index[stacks[1]->count - 1]
			< stacks[0]->index[stacks[0]->count - 1])
		{
			operate(stacks, vector, 3);
		}
		else
			operate(stacks, vector, 5);
	}
}

static int	split_stack_b(t_stack *current, int subedge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = (current->index[current->count - 1]
			+ current->index[current->count - (subedge / 2 + 1)]
			+ current->index[current->count - subedge]) / 3;
	printf("id: %c\n", current->id);
	printf("\nsubedge: %i\n", subedge);
	printf("current count: %i\n", current->count);
	printf("pivot: %i\n", pivot);
	sleep(1);
	temp = current->count - 1;
	i = 0;
	while (i <= temp)
	{
		if (current->index[current->count - 1] >= pivot)
			operate(stacks, vector, 3);
		else
			operate(stacks, vector, 6);
		i++;
	}
	return (temp + 1 - current->count);
}

static void	quicksort_b(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector)
{
	if (*edges_b > 0)
	{
		printf("\nedge b: %i\n", *edges_b);
		print_stack(stacks[0]);
		print_stack(stacks[1]);
		*edges_a = split_stack_b(current, *edges_b, stacks, vector);
		edges_a++;
		edges_b--;
		quicksort_a(current, edges_a, edges_b, stacks, vector);
		// edges_a--;
		quicksort_b(current, edges_a, edges_b, stacks, vector);
	}
}

static int	split_stack_a(t_stack *current, int subedge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = (current->index[current->count - 1]
			+ current->index[current->count - subedge / 2]
			+ current->index[current->count - subedge]) / 3;
	printf("id: %c\n", current->id);
	printf("pivot: %i\n", pivot);
	sleep(1);
	temp = current->count - 1;
	i = 0;
	while (i <= temp)
	{
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else
			operate(stacks, vector, 5);
		i++;
	}
	return (temp + 1 - current->count);
}

static void	quicksort_a(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector)
{
	if (*edges_a > 0)
	{
		printf("\nedge a: %i\n", *edges_a);
		print_stack(stacks[0]);
		print_stack(stacks[1]);
		*edges_b = split_stack_a(current, *edges_a, stacks, vector);
		edges_b++;
		edges_a--;
		quicksort_b(stacks[1], edges_a, edges_b, stacks, vector);
		// edges_b--;
		quicksort_a(current, edges_a, edges_b, stacks, vector);
	}
}

static int	split_stack_start(t_stack *current, int subedge, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;

	pivot = (current->index[current->count - 1]
			+ current->index[(current->count / 2) / 2]
			+ current->index[0]) / 3;
	printf("id: %c\n", current->id);
	printf("pivot: %i\n", pivot);
	sleep(1);
	temp = current->count - 1;
	i = 0;
	while (i <= temp)
	{
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else
			operate(stacks, vector, 5);
		i++;
	}
	return (temp + 1 - current->count);
}

static void	quicksort_start(t_stack *current, int *edges_a, int *edges_b, t_stack **stacks, t_vector *vector)
{
	if (current->count > 0)
	{
		printf("\nedge start: %i\n", *edges_a);
		print_stack(stacks[0]);
		print_stack(stacks[1]);
		*edges_b = split_stack_start(current, *edges_a, stacks, vector);
		edges_b++;
		quicksort_start(current, edges_a, edges_b, stacks, vector);
		edges_b--;
		quicksort_b(stacks[1], edges_a, edges_b, stacks, vector);
	}
}

void	sort(t_stack **stacks, t_vector *vector)
{
	int	*edges_a;
	int	*edges_b;
	print_stack(stacks[0]);
	print_stack(stacks[1]);

	int	count = 50000;
	edges_a = malloc(sizeof(int) * count);
	edges_b = malloc(sizeof(int) * count);
	ft_bzero(edges_a, count);
	ft_bzero(edges_b, count);
	quicksort_start(stacks[0], &edges_a[count / 2], &edges_b[count / 2], stacks, vector);
	// merge_stacks(stacks, vector);
}
