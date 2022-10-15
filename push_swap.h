/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:23 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/15 14:18:44 by lorbke           ###   ########.fr       */
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

t_stack	**init_stacks(t_stack **stacks, char **input, size_t count);

void	swap_top_of_stack(t_stack *stack);
void	push_to_stack(t_stack *from, t_stack *to);
void	rotate_stack_up(t_stack *stack);
void	rotate_stack_down(t_stack *stack);

void	operate(t_stack **stacks, t_vector *vector, int operation);

void	sort(t_stack **stacks, t_vector *vector);

#endif
