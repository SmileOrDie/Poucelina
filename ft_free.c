/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:33:00 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/01 12:33:30 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		free_elem(t_list **elem)
{
	(*elem)->next = NULL;
	if((*elem)->var)
		free((*elem)->var);
	if((*elem)->value)
		free((*elem)->value);
	free(*elem);
}

void		ft_free_tab(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

int			ft_atoi_exit(const char *str, int *i)
{
	int		val;
	int		neg;

	val = 0;
	if (str == NULL || str[0] == '\0')
		return (val);
	while (str[0] == '\n' || str[0] == '\v' || str[0] == '\t' ||\
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
	if(*str != '\0')
	{
		*i = -1;
		return (0);
	}
	return (val * neg);
}


void		ft_exit(char **str)
{
	int i;
	int er;
	char *tmp;

	if (str[2])
	{
		tmp = ft_strjoin(str[1],str[2]);
		i = ft_atoi_exit(tmp, &er);
	}
	else
	{
		if (str[1])
			i = ft_atoi_exit(str[1], &er);
	}
	if (str[2] && er == -1)
		ft_putstr_fd("exit: Expression Syntax.\n", 2);
	else
		exit((unsigned char)i);
}
