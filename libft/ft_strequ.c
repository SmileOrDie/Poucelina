/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:57 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/05 13:46:24 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	eq;

	if (s1 == NULL || s2 == NULL)
		return (0);
	eq = (ft_strcmp(s1, s2) == 0 ? 1 : 0);
	return (eq);
}
