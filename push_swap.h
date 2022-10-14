/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:23 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 22:06:16 by lorbke           ###   ########.fr       */
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

typedef struct s_stack
{
	char			id;
	int				*index;
	size_t			count;
}	t_stack;

// test functions
void	print_stack(t_stack *stack);

void	print_error(void);

int		*get_int_arr_index(int *int_arr, size_t count);
int		*str_arr_to_int_arr(char **str, size_t count);
t_stack	**init_stacks(t_stack **stacks, char **input, size_t count);

void	swap_top_of_stack(t_stack *stack, t_vector *vector, int combine);
void	push_to_stack(t_stack *from, t_stack *to, t_vector *vector);
void	rotate_stack_up(t_stack *stack, t_vector *vector, int combine);
void	rotate_stack_down(t_stack *stack, t_vector *vector, int combine);

void	swap_top_of_both_stacks(t_stack **stacks, t_vector *vector);
void	rotate_both_stacks(t_stack **stacks, t_vector *vector);
void	rotate_both_stacks_up(t_stack **stacks, t_vector *vector);

#endif
