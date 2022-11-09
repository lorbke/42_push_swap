/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:23 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/09 21:13:31 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"
# include "ft_vector.h"

typedef struct s_stack
{
	int	*index;
	int	count;
}	t_stack;

// error
void	ps_print_error(void);

// parse_args
int		ps_parse_args(int argc, char *argv[]);

// index_args
int		*get_int_arr_index(int *int_arr, int count);
int		*str_arr_to_int_arr(char **str, t_stack **stacks);

// stack_utils
void	ps_free_stacks(t_stack **stacks);
int		*arr_reverse(int *int_arr, int count);
int		*copy_array(int *dst, int *src, int n);
t_stack	**ps_init_stacks(char **input, int count);

// operator_utils
void	ps_swap_top_of_stack(t_stack *stack);
void	ps_push_to_stack(t_stack *from, t_stack *to);
void	ps_rotate_stack_up(t_stack *stack);
void	ps_rotate_stack_down(t_stack *stack);

// operator
void	ps_operate(t_stack **stacks, t_vector *vector, int operation);

#endif
