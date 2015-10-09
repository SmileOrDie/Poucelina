/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 13:02:15 by shamdani          #+#    #+#             */
/*   Updated: 2015/09/24 13:05:26 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int			count_words(char *s)
{
	int			counter;
	int			in_substr;

	in_substr = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (in_substr == 1 && (*s == '\t' || *s == ' ' || *s == '\n'))
			in_substr = 0;
		if (in_substr == 0 && (*s != '\t' && *s != ' ' && *s != '\n'))
		{
			in_substr = 1;
			counter++;
		}
		s++;
	}
	return (counter + 1);
}

static char			**ft_split2(char *str, char **split, int *i, int j)
{
	int				k;

	k = *i;
	while (str[k] && (str[k] != ' ' && str[k] != '\t' && str[k] != '\n'))
		k++;
	split[j] = (char*)malloc(sizeof(char) * (k - *i) + 1);
	k = 0;
	while (str[*i] && (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n'))
	{
		split[j][k] = str[*i];
		(*i)++;
		k++;
	}
	split[j][k] = '\0';
	return (split);
}

char				**ft_split(char *str)
{
	int				i;
	int				j;
	int				k;
	char			**split;

	i = 0;
	j = 0;
	k = 0;
	if (!str)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * count_words(str) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			split = ft_split2(str, split, &i, j);
			j++;
			i--;
		}
		i++;
		k = 0;
	}
	split[j] = NULL;
	return (split);
}
