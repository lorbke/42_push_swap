/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:19:32 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 02:29:10 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_solution(t_stack **solution_state, t_stack **stacks)
{
	int	i;

	if (solution_state[0]->count != stacks[0]->count
		|| solution_state[1]->count != stacks[1]->count)
		return (0);
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

static void	find_path(int level, t_intvec *path, t_stack **solution_state, t_stack **stacks, t_intvec *vec)
{
	int	operation;

	operation = 0;
	while (operation < 11)
	{
		if (level < path->count)
		{
			printf("%i", operation);
			fflush(stdout);
			test_operate(stacks, vec, operation);
			if (check_solution(solution_state, stacks))
			{
				path->array = copy_array(path->array, vec->array, vec->count);
				path->count = vec->count;
				return ;
			}
			else
				find_path(level + 1, path, solution_state, stacks, vec);
			reverse_operate(stacks, vec, operation);
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
	stacks_copy = copy_stacks(stacks_copy, stacks);
	vec = intvec_init(vec, 10);
	path = intvec_init(path, 10);
	vec->count = 0;
	test_operate(solution_state, vec, 4);
	printf("\n\n");
	print_stack(solution_state[1]);
	printf("\n\n");
	find_path(0, path, solution_state, stacks_copy, vec);
	printf("path: %i\n", path->array[0]);
	path_operate(stacks, path, vector);
	print_stack(stacks[0]);
	print_stack(stacks[1]);
	printf("\n\n");
	printf("solution: %i\n", check_solution(solution_state, stacks));
}
