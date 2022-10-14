/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:24:26 by lorbke            #+#    #+#             */
/*   Updated: 2022/10/14 22:04:55 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static void	*ft_realloc_vector(void *ptr, size_t size, size_t size_src)
{
	void	*ptr_cpy;

	if (ptr == NULL)
		return (NULL);
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	ptr_cpy = (void *)malloc(sizeof(char) * size);
	if (ptr_cpy == NULL)
		return (NULL);
	ptr_cpy = ft_memmove(ptr_cpy, ptr, size_src);
	free(ptr);
	return (ptr_cpy);
}

void	ft_vector_init(t_vector *vector)
{
	vector->len = 0;
	vector->temp_len = 0;
	vector->output = (char *)malloc(sizeof(char) * 1);
}

void	ft_vector_push_back(t_vector *vector, char c, int n)
{
	if (vector->temp_len + n >= vector->len)
	{
		vector->len += n + 100;
		vector->output = ft_realloc_vector(vector->output, vector->len,
				vector->temp_len);
	}
	while (n > 0)
	{
		vector->output[vector->temp_len] = c;
		vector->temp_len++;
		n--;
	}
}
