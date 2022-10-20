/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intvec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:48:28 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/20 01:23:15 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intvec	*intvec_init(t_intvec *vec, int count)
{
	vec = malloc(sizeof(t_intvec));
	vec->array = malloc(sizeof(int) * count);
	vec->count = count;
	return (vec);
}

void	intvec_push_back(t_intvec *vec, int n)
{
	vec->count++;
	vec->array[vec->count - 1] = n;
}
