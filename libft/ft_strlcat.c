/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:03:06 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/21 20:49:56 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			tmp_size;
	size_t			len;
	char			*tmp_dst;
	const char		*tmp_src;

	tmp_size = size;
	tmp_dst = dst;
	tmp_src = src;
	while (*tmp_dst != '\0' && tmp_size-- != 0)
		tmp_dst++;
	len = tmp_dst - dst;
	tmp_size = size - len;
	if (tmp_size == 0)
		return (len + ft_strlen((char *)tmp_src));
	while (*tmp_src != '\0')
	{
		if (tmp_size != 1)
		{
			*tmp_dst++ = *tmp_src;
			tmp_size--;
		}
		tmp_src++;
	}
	*tmp_dst = '\0';
	return (len + (tmp_src - src));
}
