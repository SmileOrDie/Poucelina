/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 11:45:52 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/05 10:10:06 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char		*ft_check_var(t_list *list, char *var)
{
	while (list)
	{
		if (list && ft_strcmp(list->var, var) == 0)
			return (list->value);
		list = list->next;
	}
	return (NULL);
}

static int	ft_cd_part2(char **str, int er, char *path, t_env *e)
{
	char	*cd;

	er = chdir(ft_check_var(e->list, "HOME"));
	er = chdir(*str + 2);
	if (er != -1)
	{
		cd = getcwd(NULL, 0);
		ft_set(e->list, "OLDPWD", path);
		ft_set(e->list, "PWD", cd);
		free(cd);
	}
	else
	{
		(**str)++;
		chdir(path);
	}
	return (er);
}

static void	error(int er, char *str)
{
	if (er == -1)
	{
		ft_putstr_fd("cd: error: ", 2);
		ft_putendl_fd(str, 2);
	}
}

static void	ft_cd_part1(char *str, int er, char *path, t_env *e)
{
	DIR		*file;
	char	*cd;

	file = opendir(str);
	if (ft_strcmp(str, "-") == 0)
	{
		ft_set(e->list, "PWD", ft_check_var(e->list, "OLDPWD"));
		ft_set(e->list, "OLDPWD", path);
		er = chdir(ft_check_var(e->list, "PWD"));
		ft_putendl(ft_check_var(e->list, "PWD"));
	}
	else if (ft_strncmp(str, "~/", 2) == 0)
		er = ft_cd_part2(&str, er, path, e);
	else if (file == NULL)
		er = -1;
	else
	{
		er = chdir(str);
		cd = getcwd(NULL, 0);
		ft_set(e->list, "OLDPWD", path);
		ft_set(e->list, "PWD", cd);
		free(cd);
	}
	error(er, str);
}

void		ft_cd(char *str, t_env *e)
{
	char	*path;
	char	*cd;

	path = getcwd(NULL, 0);
	if (str && ft_strcmp(str, "~") != 0)
		ft_cd_part1(str, 1, path, e);
	else
	{
		chdir(ft_check_var(e->list, "HOME"));
		ft_set(e->list, "OLDPWD", path);
		cd = getcwd(NULL, 0);
		ft_set(e->list, "PWD", cd);
		free(cd);
	}
	free(path);
}
