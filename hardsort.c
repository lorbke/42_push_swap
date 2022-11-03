/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:18:43 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/21 02:58:43 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 4);
	operate(stacks, vector, 0);
	operate(stacks, vector, 5);
	operate(stacks, vector, 5);
	operate(stacks, vector, 3);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
}

static void	case_two(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 5);
	operate(stacks, vector, 5);
	operate(stacks, vector, 4);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 3);
}

static void	case_three(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 4);
	operate(stacks, vector, 5);
	operate(stacks, vector, 5);
	operate(stacks, vector, 3);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
}

static void	case_four(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 5);
	operate(stacks, vector, 0);
	operate(stacks, vector, 8);
}

static void	r_case_one(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 4);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 0);
	operate(stacks, vector, 3);
}

static void	r_case_two(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 4);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 3);
}

static void	r_case_three(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 4);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 0);
	operate(stacks, vector, 5);
	operate(stacks, vector, 3);
	operate(stacks, vector, 8);
}

static void	r_case_four(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 0);
}

static void	r_case_five(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 0);
	operate(stacks, vector, 8);
}

static void	r_case_six(t_stack **stacks, t_vector *vector)
{
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
	operate(stacks, vector, 8);
}

static void	hardsort_three(int swap, t_stack **stacks, t_vector *vector)
{
	int	one;
	int	two;
	int	three;

	if (swap == 1)
	{
		one = stacks[0]->index[stacks[0]->count - 1];
		two = stacks[0]->index[stacks[0]->count - 2];
		three = stacks[0]->index[stacks[0]->count - 3];
		if (one > two && two > three)
			case_one(stacks, vector);
		else if (one < two && two > three && one > three)
			case_two(stacks, vector);
		else if (one > two && two < three && one > three)
			case_three(stacks, vector);
		else if (one < two && two > three && one < three)
			case_four(stacks, vector);
		else if (one > two && two < three && one < three)
			operate(stacks, vector, 0);
	}
	else
	{
		one = stacks[0]->index[0];
		two = stacks[0]->index[1];
		three = stacks[0]->index[2];
		if (one < two && two < three && one < three)
			r_case_one(stacks, vector);
		else if (one < two && two > three && one < three)
			r_case_two(stacks, vector);
		else if (one > two && two < three && one < three)
			r_case_three(stacks, vector);
		else if (one > two && two < three && one > three)
			r_case_four(stacks, vector);
		else if (one < two && two > three && one > three)
			r_case_five(stacks, vector);
		else if (one > two && two > three && one > three)
			r_case_six(stacks, vector);
	}
}

void	hardsort_two(int swap, t_stack **stacks, t_vector *vector)
{
	if (swap == -1 && stacks[0]->count > 2)
	{
		operate(stacks, vector, 8);
		operate(stacks, vector, 8);
	}
	if (!is_substack_sorted(stacks[0]))
		operate(stacks, vector, 0);
}

void	hardsort(int edge, int swap, t_stack **stacks, t_vector *vector)
{
	int	i;

	if (is_stack_sorted(edge, swap, stacks[0]))
	{
		while (edge && swap == -1)
		{
			operate(stacks, vector, 8);
			edge--;
		}	
		return ;
	}
	if (edge == 2)
		hardsort_two(swap, stacks, vector);
	else if (edge == 1 && swap == -1)
		operate(stacks, vector, 8);
	// if (edge == 5)
	// {
	// 	operate(stacks, vector, 4);
	// 	operate(stacks, vector, 4);
	// 	if (is_stack_sorted(edge, swap, stacks[1]))
	// 		operate(stacks, vector, 1);
	// 	hardsort_three(swap, stacks, vector);
	// 	i = 0;
	// 	while (edge > 3)
	// 	{
	// 		while (stacks[0]->index[stacks[0]->count - 1]
	// 			!= stacks[1]->index[stacks[1]->count - 1] + 1)
	// 		{
	// 			operate(stacks, vector, 5);
	// 		}
	// 		edge--;
	// 	}
	// }
	else if (edge == 3)
		hardsort_three(swap, stacks, vector);
}

	// 1 2 3 x 
	// rra 
	// pb 
	// rra rra
	// sa
	// pa

	// 1 3 2 x
	// rra 
	// pb 
	// rra rra
	// pa

	// 2 1 3 x
	// rra
	// pb 
	// rra rra
	// sa 
	// ra 
	// pa 
	// rra

	// 3 1 2 x
	// rra rra rra
	// sa 

	// 2 3 1 x 
	// rra rra 
	// sa 
	// rra

	// 3 2 1 x
	// rra rra rra

// ------------------
	// x 1 2 3
	// bp 
	// sa 
	// ra ra 
	// pa 
	// rra rra

	// x 1 3 2
	// ra ra
	// pb 
	// rra rra 
	// pa 

	// x 2 1 3
	// pb 
	// ra ra 
	// pa 
	// rra rra

	// x 3 1 2
	// sa 

	// x 2 3 1
	// ra 
	// sa 
	// rra 

	// x 3 2 1
	// -