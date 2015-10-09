/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 17:16:16 by shamdani          #+#    #+#             */
/*   Updated: 2015/09/28 20:10:55 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "shell.h"
#include <stdio.h>

int			ft_strlen_spe(char *str, char c)
{
	int		i;

	i = 0;
	if(!c || !str)
		return (0);
	while(str[i] && str[i] != c)
		i++;
	return(i);
}

t_line		*ft_check_line(char *line/*, t_env *e*/)
{
	t_line	*list;
	t_line	*begin;
	char	*tmp;
	char	*tmp2;
	int		i;
	int		j;

	i = 0;
	if (!(list = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	begin = list;
	while (line[i])
	{
		ft_putstr("\ntest : ");
		ft_putnbr(i);
		if (line[i] == '\"')
		{
			j = i + 1;
			while (line[j] != '\"' && line[j])
				j++;
			list->val = ft_strsub(line, i, (j - i));
			list->str = 1;
			i = j;
			if (!line[j])
			{
				free(line);
				line = ft_strjoin(list->val, "\n");
				while (get_next_line(0, &tmp2))
				{
					write(1, "dquote>", 7);
					tmp = ft_strjoin(line, tmp2);
					free(line);
					if (ft_strchr(tmp2, '\"') != NULL)
					{
						free(list->val);
						list->val = ft_strdup(tmp);
						break;
					}
					line = tmp;
				}
			}
		}
		else if (line[i] == '\'')
		{
			j = i + 1;
			while (line[j] != '\'' && line[j])
				j++;
			list->val = ft_strsub(line, i + 1, (j - i) - 1);
			list->str = 1;
			i = j;
			if (!line[i])
			{
				//free(line);
				line = ft_strjoin(list->val, "\n");
				while (get_next_line(0, &tmp2))
				{
					write(1, "quote>", 7);
					tmp = ft_strjoin(line, tmp2);
					//free(line);
					if (ft_strchr(tmp, '\'') != NULL)
					{
						//free(list->val);
						list->val = ft_strsub(tmp, i, strlen(tmp) - 1);
						line = ();
						free(tmp);
						break;
					}
					//line = tmp;
				}
			}
		}

		if (line[i + 1])
		{
			if (!(list->next = (t_line*)malloc(sizeof(t_line))))
				return(NULL);
			if (tmp)
				list->val = ft_strdup(tmp);
			else
				list->val = ft_strdup(line);
			list = list->next;
		}
		else
			list->next = NULL;
		i++;
	}
	if (tmp)
		free(tmp);
	return (begin);
}

int main(int ac, char **av)
{
	t_line *list;
	if (ac > 1)
	{
		getchar();
		list = ft_check_line(av[1]);
		ft_putendl("\nsuccess!");
		while (list)
		{
			getchar();
			if(list->val)
				ft_putendl(list->val);
			ft_putnbr(list->str);
			write(1,"\n",1);
			list = list->next;
		}
	}
	return (0);
}
