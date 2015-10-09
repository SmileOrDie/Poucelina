/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:07:29 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/10 15:07:34 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p_s1;
	char	*p_s2;

	p_s1 = (char*)s1;
	p_s2 = (char*)s2;
	while (n--)
	{
		if (*p_s1 != *p_s2)
			return ((unsigned char)*p_s1 - (unsigned char)*p_s2);
		p_s1++;
		p_s2++;
	}
	return (0);
}
