/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 12:18:24 by shamdani          #+#    #+#             */
/*   Updated: 2014/12/24 13:10:20 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_word_counter(const char *s, char c)
{
	int			counter;
	int			in_substr;

	in_substr = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (in_substr == 1 && *s == c)
			in_substr = 0;
		if (in_substr == 0 && *s != c)
		{
			in_substr = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static int		ft_word_len(const char *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t;
	int			nb_word;
	int			index;

	if (!s)
		return ((char **)s);
	index = 0;
	nb_word = ft_word_counter((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_word_counter((const char *)s, c) + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub((const char *)s, 0, \
									ft_word_len((const char *)s, c));
		if (t[index] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
