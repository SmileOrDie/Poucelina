/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:33:31 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/08 13:44:00 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		creat_env(char ***env)
{
	if (!(*env = (char **)malloc(sizeof(char *) * 6)))
		return ;
	(*env)[0] = ft_strjoin("PWD=", getcwd(NULL, 0));
	(*env)[1] = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
	(*env)[2] = ft_strjoin("HOME=", getcwd(NULL, 0));
	(*env)[3] = ft_strdup("SHLVL=2");
	(*env)[4] = ft_strdup("USER=Mishell");
	(*env)[5] = NULL;
}

void		ft_init_line(t_env **env)
{
	(*env)->local_variables = ht_create(65536);
	(*env)->line[_POSIX2_LINE_MAX - 1] = '\0';
	(*env)->len = sizeof((*env)->line) - 1;
	ft_memcpy((*env)->pwd, ft_check_var((*env)->list, "PWD"), (sizeof((*env)->pwd) - 1));
	ft_memcpy((*env)->home, ft_check_var((*env)->list, "HOME"), (sizeof((*env)->home) - 1));
	(*env)->pwd_len = ft_strlen((*env)->pwd);
	(*env)->home_len = ft_strlen((*env)->home);
}

t_env		*ft_init(char **env)
{
	char	*shlvl;
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (ERROR);
	if (!*env)
	{
		creat_env(&e->env);
		e->list = ft_create_list(e->env);
	}
	else
	{
		e->list = ft_create_list(env);
		shlvl = ft_itoa(ft_atoi(ft_check_var(e->list, "SHLVL")) + 1);
		ft_set(e->list, "SHLVL", shlvl);
		free(shlvl);
		e->env = conv_lst(e->list);
	}
	ft_init_line(&e);
	e->prompt = ft_strjoin(ft_check_var(e->list, "USER"), "$>");
	e->shell = ft_strdup("MISHELL");
	ft_putstr(e->prompt);
	return (e);
}
