/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:23 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 16:05:42 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/ft_vector.h"

typedef struct s_stack
{
	char			id;
	int				*index;
	int				count;
}	t_stack;

// error
void	ps_print_error(void);

// parse_args
int		ps_parse_args(int argc, char *argv[]);

// index_args
int		*get_int_arr_index(int *int_arr, int count);
int		*str_arr_to_int_arr(char **str, int count);

// stack_utils
int		*copy_array(int *dst, int *src, int n);
t_stack	**ps_init_stacks(t_stack **stacks, char **input, int count);

// operator_utils
void	ps_swap_top_of_stack(t_stack *stack);
void	ps_push_to_stack(t_stack *from, t_stack *to);
void	ps_rotate_stack_up(t_stack *stack);
void	ps_rotate_stack_down(t_stack *stack);

// operator
void	ps_operate(t_stack **stacks, t_vector *vector, int operation);

// hardsort
void	ps_hardsort_two(int swap, t_stack **stacks, t_vector *vector);
void	ps_hardsort(int edge, int swap, t_stack **stacks, t_vector *vector);

// subsequence
int		*ps_get_lds(t_stack *stack, int edge, int swap);

// insertionsort
void	ps_insort(int edge, int swap, t_stack **stacks, t_vector *vector);

// quicksort
void	ps_qsort_a(int edge, int swap, t_stack **stacks, t_vector *vector);

// hardsort_cases
void	ps_case_one(t_stack **stacks, t_vector *vector);
void	ps_case_two(t_stack **stacks, t_vector *vector);
void	ps_case_three(t_stack **stacks, t_vector *vector);
void	ps_case_four(t_stack **stacks, t_vector *vector);

// sort_utils
int		ps_is_stack_sorted(int edge, int swap, t_stack *stack);
int		ps_is_top_sorted(t_stack *stack);
int		ps_get_highest(t_stack *stack);

#endif
