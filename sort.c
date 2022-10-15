/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/15 23:24:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	split_stacks(t_stack **stacks, t_vector *vector)
{
	int	i;
	int	temp;

	i = 1;
	temp = stacks[0]->count / 2;
	while (i <= temp)
	{
		operate(stacks, vector, 4);
		i++;
	}
}

static void	find_swap_operation(t_stack **stacks, t_vector *vector)
{
	if (stacks[0]->index[stacks[0]->count - 1]
		> stacks[0]->index[stacks[0]->count - 2]
		&& stacks[1]->index[stacks[1]->count - 1]
		> stacks[1]->index[stacks[1]->count - 2])
		operate(stacks, vector, 2);
	else if (stacks[0]->index[stacks[0]->count - 1]
		> stacks[0]->index[stacks[0]->count - 2])
		operate(stacks, vector, 0);
	else if (stacks[1]->index[stacks[1]->count - 1]
		> stacks[1]->index[stacks[1]->count - 2])
		operate(stacks, vector, 1);
}

static void	find_rotate_operation(t_stack **stacks, t_vector *vector)
{
	if (!is_stack_sorted(stacks[0]) && !is_stack_sorted(stacks[1]))
		operate(stacks, vector, 7);
	else if (!is_stack_sorted(stacks[0]))
		operate(stacks, vector, 5);
	else if (!is_stack_sorted(stacks[1]))
		operate(stacks, vector, 6);
}

// static void	merge_stacks(t_stack **stacks, t_vector *vector)
// {
// 	int	temp;

// 	temp = stacks[1]->count;
// 	while (stacks[1]->count)
// 	{
// 		if (stacks[0]->index[stacks[0]->count - 1]
// 			> stacks[1]->index[stacks[0]->count - 1])
// 		{
// 			operate(stacks, vector, 3);
// 			if (stacks[1]->count)
// 				operate(stacks, vector, 5);
// 		}
// 		sleep(1);
// 		print_stack(stacks[0]);
// 		print_stack(stacks[1]);
// 		printf("\n\n");
		
// 	}
// 	// while ()
// 	// 	operate(stacks, vector, )
// }

// static void	merge_sort(t_stack **stacks, t_vector *vector)
// {
	
//   falls (Größe von liste <= 1) dann antworte liste
//   sonst
//      halbiere die liste in linkeListe, rechteListe
//      linkeListe = mergesort(linkeListe)
//      rechteListe = mergesort(rechteListe)
//      antworte merge(linkeListe, rechteListe)
// }

static void	merge_stacks(t_stack **stacks, t_vector *vector)
{
	while (stacks[1]->count)
	{
		if (stacks[1]->index[stacks[1]->count - 1]
			< stacks[0]->index[stacks[0]->count - 1])
		{
			operate(stacks, vector, 3);
			operate(stacks, vector, 5);
		}
		else
			operate(stacks, vector, 5);
	}
	operate(stacks, vector, 5);
	operate(stacks, vector, 5);
	operate(stacks, vector, 5);
}

// void	sort(t_stack **stacks, t_vector *vector)
// {
// 	split_stacks(stacks, vector);
// 	print_stack(stacks[0]);
// 	print_stack(stacks[1]);
// 	merge_stacks(stacks, vector);
// }

// modified bubble sort
void	sort(t_stack **stacks, t_vector *vector)
{
	int	i;

	split_stacks(stacks, vector);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	while (!is_stack_sorted(stacks[0]) || !is_stack_sorted(stacks[1]))
	{
		i = 0;
		while (i < stacks[0]->count - 1)
		{
			// printf("i: %i", i);
			find_swap_operation(stacks, vector);
			i++;
			// printf("\n\n");
			// printf("after swap:\n");
			// print_stack(stacks[0]);
			// print_stack(stacks[1]);
			// printf("\n\n");
			// sleep(1);
			find_rotate_operation(stacks, vector);
			// printf("after rotate:\n");
			// print_stack(stacks[0]);
			// print_stack(stacks[1]);
		}
		find_rotate_operation(stacks, vector);
		// if (stacks[1]->count != stacks[0]->count)
		// 	operate(stacks, vector, 6);
		// printf("\n\n");
		// printf("%s", ft_vector_get_output(vector));
	}
	merge_stacks(stacks, vector);
	// 	printf("counter: %i\n", counter);
	// printf("is sorted: %i\n\n", is_stack_sorted(stacks[1]));
}
