/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:08 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/18 22:31:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 	- parse_input -> stack_a
// 		- string_to_int_array -> stack_a
// 		- replace_int_with_index -> stack_a
// 	- sort_stack -> stack_a
// 		- create_stack_b -> stack_b
// 		- group together operations to a set of operations, then bunch of if 
//		  statmements to execute most sensible operation

// set of operations
// - print each time when called

// handle_error


// stack a has to be sorted and stack b has to be empty at the end


// remember to reinclude flags

// vector is not catching errors correctly

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack		**stacks;
	t_vector	vector;

	if (argc <= 1)
		print_error();
	stacks = init_stacks(stacks, &argv[1], argc - 1);
	ft_vector_init(&vector);

	print_stack(stacks[0]);
	print_stack(stacks[1]);

	sort(stacks, &vector);

	printf("\n\n%s", ft_vector_get_output(&vector));
	print_stack(stacks[0]);
	print_stack(stacks[1]);


	return (0);
}
