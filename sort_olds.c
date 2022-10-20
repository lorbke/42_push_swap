/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_olds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:16:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 16:56:43 by lorbke           ###   ########.fr       */
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


//----------------quick sort--------------


// advanced pivot
static int	get_pivot(t_stack *stack, int first, int last)
{
	int	pivot;
	int	temp;

	pivot = 0;
	temp = first;
	while (first >= last)
	{
		pivot += stack->index[first];
		first--;
	}
	pivot /= temp - last + 1;
	return (pivot);
}

// static int	get_pivot(t_stack *stack, int first, int last)
// {
// 	int	pivot;
// 	int	temp;

// 	pivot = 0;
// 	temp = first;
// 	while (first >= last)
// 	{
// 		pivot += stack->index[first];
// 		first--;
// 	}
// 	pivot /= temp - last + 1;
// 	return (pivot);
// }

// static int	split_substack(int from, t_stack **stacks, t_vector *vector, int first, int last)
// {
// 	int	pivot;
// 	int new_subcount;
// 	int	temp;
// 	int	temp_first;
// 	int	temp_last;

// 	temp = first - last;
// 	temp_first = first;
// 	temp_first = last;
// 	// printf("old first: %i\n", temp_first);
// 	// printf("old last: %i\n", temp_last);
// 	// printf("old subcount: %i\n", temp);
// 	pivot = get_pivot(stacks[from], first, last);
// 	new_subcount = 0;
// 	while (first >= last)
// 	{
// 		if (from == 0)
// 			if (stacks[from]->index[first] <= pivot)
// 			{
// 				operate(stacks, vector, 4 - from);
// 				first--;
// 			}
// 			else
// 			{
// 				operate(stacks, vector, 5 + from);
// 				new_subcount++;
// 				last++;
// 			}
// 		else
// 		{
// 			if (stacks[from]->index[first] >= pivot)
// 			{
// 				operate(stacks, vector, 4 - from);
// 				first--;
// 			}
// 			else
// 			{
// 				operate(stacks, vector, 5 + from);
// 				new_subcount++;
// 				last++;
// 			}
// 		}
// 		print_stack(stacks[0]);
// 		print_stack(stacks[1]);
// 		printf("stack: %i\n", from);
// 		printf("first: %i\n", first);
// 		printf("last: %i\n", last);
// 		printf("pivot: %i\n", pivot);
// 		printf("stack count: %zu\n", stacks[from]->count);
// 		printf("new subcount: %i\n", new_subcount);
// 		sleep(1);
// 		printf("\n\n");
// 	}
// 	return (new_subcount);
// }

// static void find_swap(int from, t_stack **stacks, t_vector *vector)
// {
// 	if (from == 0)
// 	{
// 		if (!is_stack_sorted(stacks[0]))
// 			operate(stacks, vector, 0);
// 	}
// 	else
// 	{
// 		if (is_stack_sorted(stacks[0]))
// 			operate(stacks, vector, 1);
// 		operate(stacks, vector, 3);
// 		operate(stacks, vector, 3);
// 	}
// }

// static void	quicksort(int from, t_stack **stacks, t_vector *vector, int first, int last)
// {
// 	int	subcount;
// 	int	new_subcount;
// 	int	opposite_subcount;

// 	printf("-------new branch-------\n");
// 	printf("branch parameter first: %i\n", first);
// 	printf("brach parameter last: %i\n", last);
// 	printf("\n");
// 	subcount = first + 1 - last;
// 	if (subcount < 3)
// 	{
// 		if (subcount < 2)
// 			return ;
// 		find_swap(from, stacks, vector);
// 		return ;
// 	}
// 	if (subcount > 0)
// 	{
// 		new_subcount = split_substack(from, stacks, vector, first, last);
// 		opposite_subcount = subcount - new_subcount;
// 		printf("opposite subcount: %i\n", opposite_subcount);
// 		first = stacks[from]->count - 1;
// 		printf("after split first: %i\n", first);
// 		last = first - (new_subcount - 1);
// 		printf("after split last: %i\n", last);
// 		printf("\n");
// 		quicksort(from, stacks, vector, first, last);
// 		// if (from == 0)
// 		// {
// 		// 	from += 1;
// 		// 	first = stacks[from]->count - 1;
// 		// 	last = first - (opposite_subcount - 1);
// 		// 	quicksort(from, stacks, vector, first, last);
// 		// }
// 		// else
// 		// {
// 		// 	from -= 1;
// 		// 	first = stacks[from]->count - 1;
// 		// 	last = first - (opposite_subcount - 1);
// 		// 	quicksort(from, stacks, vector, first, last);
// 		// }
// 	}
// }

// rotation adjustment
static int	split_stack_a(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	pivot;
	int	temp;
	int	i;
	int	rotations;

	rotations = 0;
	swap = 1;
	if (swap == -1)
			pivot = (current->index[0]
				+ current->index[0 + (edge / 2 + 1)]
				+ current->index[edge - 1]) / 3;
	else
		pivot = (current->index[current->count - 1]
				+ current->index[current->count - (edge / 2 + 1)]
				+ current->index[current->count - edge]) / 3;
	temp = current->count - 1;
	i = current->count - edge;
	while (i <= temp)
	{
		if (swap == -1)
			operate(stacks, vector, 8);
		if (current->index[current->count - 1] <= pivot)
			operate(stacks, vector, 4);
		else if (swap == 1)
		{
			operate(stacks, vector, 5);
			rotations++;
		}
		i++;
	}
	while (rotations)
	{
		operate(stacks, vector, 8);
		rotations--;
	}
	return (temp + 1 - current->count);
}
