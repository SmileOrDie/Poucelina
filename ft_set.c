/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:28:01 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/05 16:58:56 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		ft_set2(t_list *tmp, t_list *prev, char *var, char *val)
{
	if (tmp != NULL)
	{
		free(tmp->value);
		tmp->value = ft_strdup(val);
	}
	else
	{
		if (!(prev->next = (t_list*)malloc(sizeof(t_list))))
			return ;
		prev->next->nb = prev->nb + 1;
		prev = prev->next;
		prev->var = ft_strdup(var);
		prev->value = ft_strdup(val);
		prev->next = NULL;
	}
}

void		ft_set(t_list *list, char *var, char *val)
{
	t_list	*tmp;
	t_list	*begin;
	t_list	*prev;

	tmp = NULL;
	begin = list;
	while (list)
	{
		prev = list;
		if (list && ft_strcmp(list->var, var) == 0)
		{
			tmp = list;
			break ;
		}
		list = list->next;
	}
	ft_set2(tmp, prev, var, val);
	list = begin;
}
