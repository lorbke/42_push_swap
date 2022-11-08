/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:08 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/08 20:26:23 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// split into directories

#include "push_swap.h"

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
	ps_qsort_a(stacks[0]->count, 1, stacks, &vector);
	write(1, ft_vector_get_output(&vector), ft_vector_get_len(&vector));
	ps_free_stacks(stacks);
	ft_vector_free(&vector);
	return (0);
}
