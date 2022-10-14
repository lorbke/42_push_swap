/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:22:26 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 20:49:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	printf("stack_%c---->", stack->id);
	int	i = 0;
	while (i < stack->count)
	{
		printf("%i ", stack->index[i]);
		i++;
	}
	printf("\n");
}
