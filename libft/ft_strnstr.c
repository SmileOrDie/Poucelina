/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:25:28 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 15:43:56 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_equal_inc(size_t j, size_t k)
{
	j++;
	k++;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
			ft_equal_inc(j, k);
		else
		{
			if (k > 0)
				i = i - (j + 1);
			j = 0;
		}
		if (s2[j] == '\0')
			return ((char*)&s1[i - j + 1]);
		i++;
	}
	return (NULL);
}
