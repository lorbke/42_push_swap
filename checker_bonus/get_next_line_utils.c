/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:31:37 by lorbke            #+#    #+#             */
/*   Updated: 2022/11/10 19:24:34 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	i;

	destlen = ft_strlen(dst);
	i = 0;
	while (src[i] != 0 && destlen + i < dstsize - 1 && dstsize > 0)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	if (destlen > dstsize || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	dst[destlen + i] = 0;
	return (ft_strlen(src) + destlen);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*sjoin;
	int		size;

	if (s1 == NULL || s2 == NULL)
	{
		free(s1);
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	sjoin = (char *)malloc(sizeof(char) * size);
	if (sjoin == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(sjoin, s1, size);
	ft_strlcat(sjoin, s2, size);
	free(s1);
	return (sjoin);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (c == 0)
		return (&((char *)s)[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (dst == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
