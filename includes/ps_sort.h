/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:03:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/09 21:13:27 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_H
# define PS_SORT_H

# include "push_swap.h"

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
