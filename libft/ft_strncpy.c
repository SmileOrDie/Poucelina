/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:12:58 by shamdani          #+#    #+#             */
/*   Updated: 2015/01/05 12:33:46 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		if (src[i] == '\0')
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
		n--;
	}
	return (dst);
}
