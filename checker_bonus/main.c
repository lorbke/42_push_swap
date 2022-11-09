/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:47:58 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/10 00:08:06 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_sort.h"

int	check_operations(t_stack **stacks, t_vector *vector)
{
	char *buffer;
	int	i;

	buffer = malloc(sizeof(char) * 4);
	while (1)
	{
		read(STDIN_FILENO, buffer, 4);
		i = 0;
		while (i < 4)
		{
			
			i++;
		}
		printf("%s\n", buffer);
	}
	// while (operation != -1)
	// 	operation = get_next_operation
	// 	operate(operation)
	// if (is_stack_sorted && stack b empty)
	// 	return (1)
	// else
	// 	return (0)
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

	if (argc <= 1)
		return (0);
	if (!ps_parse_args(argc, argv))
		ps_print_error();
	stacks = ps_init_stacks(&argv[1], argc - 1);
	if (!stacks)
		ps_print_error();
	if (stacks[0]->count == 1
		|| ps_is_stack_sorted(stacks[0]->count, 1, stacks[0]))
	{
		ps_free_stacks(stacks);
		return (0);
	}
	ft_vector_init(&vector);

	check_operations(stacks, &vector);

	ps_free_stacks(stacks);
	ft_vector_free(&vector);
	return (0);
}
