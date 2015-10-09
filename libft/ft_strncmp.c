/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:43:30 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/06 09:43:37 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n > len1)
		n = len1 + 1;
	if (n > len2)
		n = len2 + 1;
	return (ft_memcmp(s1, s2, n));
}
