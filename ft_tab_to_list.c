/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:36:06 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/04 10:21:40 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		assign_elements(char **env, t_list *list, int i)
{
	char	**tmp;

	tmp = ft_strsplit(env[i], '=');
	list->var = ft_strdup(tmp[0]);
	list->value = ft_strdup(tmp[1]);
	list->nb = i;
	ft_free_tab(&tmp);
}

t_list		*ft_create_list(char **env)
{
	t_list	*list;
	t_list	*begin;
	int		i;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	begin = list;
	i = 0;
	while (env[i])
	{
		assign_elements(env, list, i);
		if (env[i + 1])
		{
			if (!(list->next = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			list = list->next;
		}
		i++;
	}
	list->next = NULL;
	return (begin);
}
