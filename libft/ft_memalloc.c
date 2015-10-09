/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:26:59 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/08 15:27:01 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	size_t			i;
	char			*init;

	i = 0;
	mem = (void *)malloc(size);
	init = (char *)mem;
	if (mem != NULL)
		while (i++ < size)
			*init++ = 0;
	return (mem);
}
