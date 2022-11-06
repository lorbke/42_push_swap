/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:09:19 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/06 00:51:24 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_empty(char *str)
{
	if (str == NULL || str[0] == 0)
		return (1);
	while (*str)
	{
		if (ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	check_signs(char *str, int i)
{
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (0);
	if (i > 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')
		return (0);
	return (1);
}

int	parse_args(int argc, char *argv[])
{
	int	i;

	argc--;
	while (argc)
	{
		if (is_empty(argv[argc]))
			return (0);
		i = 0;
		while (argv[argc][i])
		{
			if (check_signs(argv[argc], i))
			{
				if (!ft_isdigit(argv[argc][i]) && argv[argc][i] != ' '
					&& argv[argc][i] != '-' && argv[argc][i] != '+')
					return (0);
			}
			else
				return (0);
			i++;
		}
		argc--;
	}
	return (1);
}
