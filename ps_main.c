/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:08 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 16:05:19 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// handle_error

// vector is not catching errors correctly

// error messages output in stderror (fd = 2)

// malloc protection

// leaks

// split into directories

// make comment for every function

// input parsing

// multiple numbers in one string

// replace atoi with strtol (CERT safe coding) (outside integer range in index args)

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
	stacks = NULL;
	stacks = ps_init_stacks(stacks, &argv[1], argc - 1);
	if (!stacks)
		ps_print_error();
	ft_vector_init(&vector);
	ps_qsort_a(stacks[0]->count, 1, stacks, &vector);
	write(1, ft_vector_get_output(&vector), ft_vector_get_len(&vector));
	return (0);
}
