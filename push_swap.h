/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:23 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 21:28:26 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/ft_vector.h"

typedef struct s_intvec
{
	int				*array;
	size_t			count;
}	t_intvec;

typedef struct s_stack
{
	char			id;
	int				*index;
	size_t			count;
}	t_stack;

// test_functions
void	print_stack(t_stack *stack);

// error
void	print_error(void);

// parse
int	*get_int_arr_index(int *int_arr, size_t count);
int	*str_arr_to_int_arr(char **str, size_t count);

// stack_utils
int	*copy_array(int *dst, int *src, size_t n);
t_stack	**init_stacks(t_stack **stacks, char **input, size_t count);
t_stack	**copy_stacks(t_stack **stacks_copy, t_stack **stacks);

// operations
void	swap_top_of_stack(t_stack *stack);
void	push_to_stack(t_stack *from, t_stack *to);
void	rotate_stack_up(t_stack *stack);
void	rotate_stack_down(t_stack *stack);

// operator
void	operate(t_stack **stacks, t_vector *vector, int operation);

// intvec_utils
t_intvec	*intvec_init(t_intvec *vec, int count);
void	intvec_push_back(t_intvec *vec, int n);

// test_operator
int		test_operate(t_stack **stacks, t_intvec *vec, int operation);

// bruteforce_utils
void	path_operate(t_stack **stacks, t_intvec *vec, t_vector *vector);
void	reverse_operate(t_stack **stacks, t_intvec *vec, int operation);

// bruteforce
void	bruteforce(int id, int edge, t_stack **stacks, t_vector *vector);

// insertionsort
void	insertionsort(int edge, int swap, t_stack **stacks, t_vector *vector);

// quicksort
void	quicksort_a(t_stack *current, int edge, int swap, t_stack **stacks, t_vector *vector);

// solution_state
void	get_solution_state_b(int edge, t_stack **stacks);
void	get_solution_state_a(int edge, t_stack **stacks);

// sort_utils
int		is_stack_sorted(t_stack *stack);
int		is_substack_sorted(t_stack *stack);
void	sort(t_stack **stacks, t_vector *vector);

#endif
