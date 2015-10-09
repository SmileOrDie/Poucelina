/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:18:05 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/04 16:19:40 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strcpy(char *dst, const char *src)
{
	size_t			len;
	unsigned int	i;
	char			*dest_;

	i = 0;
	dest_ = dst;
	len = ft_strlen(src);
	while (i <= len)
	{
		dest_[i] = src[i];
		i++;
	}
	return (dst);
}
