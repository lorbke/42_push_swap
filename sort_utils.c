/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:16:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/16 18:53:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	split_stacks(t_stack **stacks, t_vector *vector)
{
	int	i;
	int	temp;

	i = 1;
	temp = stacks[0]->count / 4;
	while (i <= temp)
	{
		operate(stacks, vector, 4);
		operate(stacks, vector, 4);
		if (!is_substack_sorted(stacks[0]) && !is_substack_sorted(stacks[1]))
			operate(stacks, vector, 2);
		else if (!is_substack_sorted(stacks[0]))
			operate(stacks, vector, 0);
		else if (!is_substack_sorted(stacks[1]))
			operate(stacks, vector, 1);
		operate(stacks, vector, 7);
		operate(stacks, vector, 7);
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

// modified bubble sort
void	bubble_sort(t_stack **stacks, t_vector *vector)
{
	int	i;

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
	// 	printf("counter: %i\n", counter);
	// printf("is sorted: %i\n\n", is_stack_sorted(stacks[1]));
}
