/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 12:06:44 by shamdani          #+#    #+#             */
/*   Updated: 2015/10/09 12:10:06 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		free_argv(t_env *env)
{
	size_t  id;

	id = 0;
	while (id < env->argv_pool_size)
	{
	//printf("Free of [%s]\n", env->argv_pool[id]);
	free(env->argv_pool[id++]);
	}
	env->argv_pool_size = 0;
}

void		cmd_exec(t_env *e, char *line)
{
	char	*tmp;
	char	*tmp2;
	// int		i;

	// i = 0;
	if (line)
	{
	// 	i = 0;
		// cmds = ft_strsplit(line, ';');
		// free(line);
		// while (cmds[i])
		// {
		if (e->last_char)
		{
			tmp = ft_strjoin(e->line, "\n");
			tmp2 = ft_strjoin(tmp, line);
			free(tmp);
			free(line);
			line = tmp2;
		//	ft_putstr(line);
		}
		ft_memcpy(e->line, line, _POSIX2_LINE_MAX);
		//ft_putstr(e->line);
		e->line[_POSIX2_LINE_MAX - 1] = '\0';
		e->len = _POSIX2_LINE_MAX;
		//debug_env(e);
		if (start_interprete(e) != NOT_CLOSED)
		//	debug_env(e);
		{
		debug_env(e);
			while (launch_interprete(e) == CONTINUE)
			{
				//put_env(env);
				check_cmd(e);
				//free_argv(env);
			}
		}
			
		//ft_free_tab(&e->env);
		e->env = conv_lst(e->list);
		// 	i++;
		// }
		// ft_free_tab(&cmds);
	}

	if (e->last_char)
	{
		debug_env(e);
		ft_memcpy(e->line, line, _POSIX2_LINE_MAX);
		ft_putstr("please close line$>");
	}
	else
		ft_putstr(e->prompt);
}

int			main(int argc, char **argv, char **env)
{
	t_env	*e;
	char	*line;

	if (argc != 1 && !argv[0])
		return (1);
	e = ft_init(env);
	while (get_next_line(0, &line))
		cmd_exec(e, line);
	ft_free_tab(&e->env);
	return (0);
}
