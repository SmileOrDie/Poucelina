/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:04:24 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/05 16:08:17 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

static char	*fln(int re, char **dest, char *dst, const char *str)
{
	ft_free_tab(&dest);
	if (re == -1)
	{
		re = access(str, X_OK);
		if (re == 0)
		{
			safe_free(dst);
			return (strdup(str));
		}
	}
	if (re == -1)
	{
		ft_putstr_fd("shell: command not found: ", 2);
		ft_putendl_fd(str, 2);
		safe_free(dst);
		return (NULL);
	}
	return (dst);
}

char		*pathsys(const char *str, t_env *e)
{
	char	**dest;
	char	*dst;
	char	*tmp;
	int		i;
	int		re;

	dst = NULL;
	i = -1;
	if (ft_check_var(e->list, "PATH") != NULL)
		dest = ft_strsplit(ft_check_var(e->list, "PATH"), ':');
	else
	{
		ft_putstr_fd("Environment is corrupted!\n", 2);
		return (NULL);
	}
	while (dest[++i])
	{
		safe_free(dst);
		tmp = ft_strjoin(dest[i], "/");
		dst = ft_strjoin(tmp, str);
		free(tmp);
		if ((re = access(dst, X_OK)) == 0)
			break ;
	}
	return (fln(re, dest, dst, str));
}
