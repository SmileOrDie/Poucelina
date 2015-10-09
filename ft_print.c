/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:31:16 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/01 12:31:50 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->var);
		write(1, "=", 1);
		ft_putendl(list->value);
		list = list->next;
	}
}

void		print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
