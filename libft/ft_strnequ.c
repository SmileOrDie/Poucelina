/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:16:57 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/12 14:17:01 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	eq;

	if (s1 == NULL || s2 == NULL)
		return (0);
	eq = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (eq);
}
