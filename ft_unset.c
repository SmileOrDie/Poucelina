/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:59:03 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/05 10:32:45 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		ft_unset(t_list *list, char **str)
{
	t_list	*begin;
	t_list	*tmp;
	int i;

	tmp = NULL;
	begin = list;
	i = 0;
	if (str[1])
	{
		while (str[++i])
		{
			while (list->next)
			{
				if (ft_strcmp(list->next->var, str[i]) == 0)
				{
					tmp = list->next;
					list->next = list->next->next;
					free_elem(&tmp);
					break ;
				}
				list = list->next;
			}
			list = begin;
		}
	}
	else
		  ft_putendl_fd("unset: Too few arguments.", 2);
}
