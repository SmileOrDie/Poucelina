/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 15:20:20 by shamdani          #+#    #+#             */
/*   Updated: 2014/12/24 13:00:32 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			trim_start;
	int				j;
	char			*new_str;

	i = 0;
	j = 0;
	trim_start = 0;
	if (!s)
		return ((char *)s);
	new_str = ft_strnew(ft_strlen(s));
	while (j < ft_strlen(s))
	{
		if (!trim_start && ft_isblank(s[j]))
			j++;
		else
		{
			trim_start = 1;
			new_str[i++] = s[j++];
		}
	}
	while (ft_isblank(new_str[--i]))
		new_str[i] = '\0';
	return (new_str);
}
