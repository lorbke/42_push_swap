/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:19:32 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 17:55:27 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_solution(t_stack **solution_state, t_stack **stacks)
{
	int	i;

	if (solution_state[0]->count != stacks[0]->count
		|| solution_state[1]->count != stacks[1]->count)
		return (0);
	i = 0;
	while (i < stacks[0]->count)
	{
		if (solution_state[0]->index[i] != stacks[0]->index[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < stacks[1]->count)
	{
		if (solution_state[1]->index[i] != stacks[1]->index[i])
			return (0);
		i++;
	}
	return (1);
}

static void	find_path(t_intvec *path, t_stack **solution_state, t_stack **stacks, t_intvec *vec)
{
	int	operation;

	// printf("vec->count: %zu\n", vec->count);
	// printf("path->count: %zu\n", path->count);
	// fflush(stdout);
	// sleep (1);
	operation = 0;
	while (operation < 11)
	{
		// printf("operation: %i\n", operation);
		if (vec->count < path->count)
		{
			if (test_operate(stacks, vec, operation))
			{
				if (check_solution(solution_state, stacks))
				{
					// print_stack(solution_state[0]);
					// print_stack(solution_state[1]);
					// print_stack(stacks[0]);
					// print_stack(stacks[1]);
					path->array = copy_array(path->array, vec->array, vec->count);
					path->count = vec->count;
					// printf("solution found %zu, vector:", vec->count);
					// int	i = 0;
					// while (i < vec->count)
					// {
					// 	printf("%i ", vec->array[i]);
					// 	i++;
					// }
					// printf("\n");
					// vec->count--;
					reverse_operate(stacks, vec, operation);
					return ;
				}
				else
					find_path(path, solution_state, stacks, vec);
				reverse_operate(stacks, vec, operation);
			}
		}
		else
			return ;
		operation++;
	}
}

// beware: fixed intvec alloc sizes are buggy combined with variable edge size
void	bruteforce(int id, int edge, t_stack **stacks, t_vector *vector)
{
	t_stack		**solution_state;
	t_stack		**stacks_copy;
	t_intvec	*vec;
	t_intvec	*path;

	solution_state = copy_stacks(solution_state, stacks);
	if (id == 0)
		get_solution_state_a(edge, solution_state);
	else
		get_solution_state_b(edge, solution_state);
	// print_stack(solution_state[0]);
	// print_stack(solution_state[1]);
	stacks_copy = copy_stacks(stacks_copy, stacks);
	vec = intvec_init(vec, 10);
	path = intvec_init(path, 10);
	// printf("\n\n");
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	vec->count = 0;
	find_path(path, solution_state, stacks_copy, vec);
	// printf("solution found %zu, path:", path->count);
	// int	i = 0;
	// while (i < path->count)
	// {
	// 	printf("%i ", path->array[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("path->count: %zu\n", path->count);
	// printf("path: %i\n", path->array[0]);
	path_operate(stacks, path, vector);
	// // operate(stacks, vector, 2);
	// print_stack(stacks[0]);
	// print_stack(stacks[1]);
	// printf("solution: %i\n", check_solution(solution_state, stacks));
	// printf("\n\n");
}
