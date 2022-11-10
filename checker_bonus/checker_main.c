/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:47:58 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/10 21:09:25 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_sort.h"
#include "get_next_line.h"

static int	get_operation_int(char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		return (0);
	else if (!ft_strncmp(operation, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "ss\n", 3))
		return (2);
	else if (!ft_strncmp(operation, "pa\n", 3))
		return (3);
	else if (!ft_strncmp(operation, "pb\n", 3))
		return (4);
	else if (!ft_strncmp(operation, "ra\n", 3))
		return (5);
	else if (!ft_strncmp(operation, "rb\n", 3))
		return (6);
	else if (!ft_strncmp(operation, "rr\n", 3))
		return (7);
	else if (!ft_strncmp(operation, "rra\n", 4))
		return (8);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		return (9);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		return (10);
	else
		return (-1);
}

static int	check_operations(t_stack **stacks, t_vector *vector)
{
	char		*next;
	int			operation;
	static char	*temp[1024];

	while (1)
	{
		next = get_next_line(temp, STDIN_FILENO);
		if (!next)
			break ;
		operation = get_operation_int(next);
		free(next);
		if (operation == -1)
		{
			free(temp[STDIN_FILENO]);
			return (-1);
		}
		ps_operate(stacks, vector, operation);
	}
	if (ps_is_stack_sorted(stacks[0]->count, 1, stacks[0]) && !stacks[1]->count)
		return (1);
	return (0);
}

void	ps_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack		**stacks;
	t_vector	vector;
	int			check;

	if (argc <= 1)
		return (0);
	if (!ps_parse_args(argc, argv))
		ps_print_error();
	stacks = ps_init_stacks(&argv[1], argc - 1);
	if (!stacks)
		ps_print_error();
	ft_vector_init(&vector);
	check = check_operations(stacks, &vector);
	if (check == 1)
		write(1, "OK\n", 3);
	else if (check == 0)
		write(1, "KO\n", 3);
	else
		write(1, "Error\n", 6);
	ps_free_stacks(stacks);
	ft_vector_free(&vector);
	return (0);
}
