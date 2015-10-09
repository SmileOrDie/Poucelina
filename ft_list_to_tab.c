/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:34:11 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/05 10:05:41 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char		*join_strenv(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(s1, "=");
	tmp2 = ft_strjoin(tmp, s2);
	free(tmp);
	return (tmp2);
}

char		**conv_lst(t_list *list)
{
	char	**tmp;
	int		i;
	t_list	*tmpl;

	i = 0;
	tmpl = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	if (!(tmp = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	list = tmpl;
	while (list)
	{
		tmp[i] = join_strenv(list->var, list->value);
		list = list->next;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
