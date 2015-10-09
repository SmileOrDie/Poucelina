/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:40 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 15:26:04 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	int		val;
	int		neg;

	val = 0;
	if (str == NULL || str[0] == '\0')
		return (val);
	while (str[0] == '\n' || str[0] == '\v' || str[0] == '\t' || \
str[0] == ' ' || str[0] == '\f' || str[0] == '\r')
		str++;
	neg = 1;
	if (*str == '-' || *str == '+')
	{
		neg = (*str == '-') ? -neg : neg;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	return (val * neg);
}
