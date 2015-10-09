/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 12:12:03 by shamdani          #+#    #+#             */
/*   Updated: 2015/06/08 13:56:40 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		ft_wrong_exit2(int sig_num)
{
	if (sig_num == SIGBUS)
		write(1, ": bus error ", 12);
	else if (sig_num == SIGSEGV)
		write(1, ": segmentation fault ", 21);
	else if (sig_num == SIGSYS)
		write(1, ": invalid system call ", 22);
	else if (sig_num == SIGALRM)
		write(1, ": timeout ", 10);
	else if (sig_num == SIGSTOP)
		write(1, ": suspended (signal) ", 21);
	else if (sig_num == SIGXCPU)
		write(1, ": cpu limit exceeded ", 21);
	else if (sig_num == SIGXFSZ)
		write(1, ": size limit exceeded ", 22);
	else if (sig_num == SIGVTALRM)
		write(1, ": virtual time alarm ", 21);
	else if (sig_num == SIGPROF)
		write(1, ": profile signal shell", 22);
	else if (sig_num == SIGUSR1)
		write(1, ": user-defined signal 1 shell", 29);
	else if (sig_num == SIGUSR2)
		write(1, ": user-defined signal 2 shell", 29);
}

static void		ft_wrong_exit(char *father, int sig_num, char *son)
{
	if (sig_num == SIGPIPE)
		return ;
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		return ;
	}
	ft_putstr(father);
	if (sig_num == SIGHUP)
		write(1, ": hangup ", 9);
	else if (sig_num == SIGILL)
		write(1, ": illegal hardware instruction ", 31);
	else if (sig_num == SIGTRAP)
		write(1, ": trace trap shell", 18);
	else if (sig_num == SIGABRT)
		write(1, ": abort ", 8);
	else if (sig_num == SIGEMT)
		write(1, ": EMT instruction ", 18);
	else if (sig_num == SIGFPE)
		write(1, ": floating point exception ", 27);
	else if (sig_num == SIGKILL)
		write(1, ": killed ", 9);
	else
		ft_wrong_exit2(sig_num);
	ft_putendl(son);
}

static void		check_cmd2(char **str, t_env *e)
{
	int			stat;
	pid_t		fat;
	char		*ret;

	ret = NULL;
	if (str[0] && ft_strcmp(str[0], "cd") == 0)
		ft_cd(str[1], e);
	else if (str[0] && ft_strcmp(str[0], "env") == 0)
		print_env(e->env);
	else if (str[0] && ft_strcmp(str[0], "exit") == 0)
		ft_exit(str);
	else if (str[0] && (ret = pathsys(str[0], e)) != NULL)
	{
		fat = fork();
		if (fat != -1)
		{
			if (fat == 0)
				execve(ret, str, e->env);
			else
				waitpid(fat, &stat, 0);
		}
		if (WIFSIGNALED(stat))
			ft_wrong_exit(e->shell, WTERMSIG(stat), ret);
	}
	safe_free(ret);
}
// #include <stdio.h>
void			check_cmd(t_env *e)
{
	char		**str;
	int			i;

	//printf("\t\tReceived command\n");
	i = 0;
	//str = ft_split(line);
	// ft_memcpy(e->line, line, _POSIX2_LINE_MAX);
	// e->len = sizeof(line) - 1;
	// launch_interprete(e);
	str = e->argv;
	put_env(e);
	if (str[0] && ft_strcmp(str[0], "setenv") == 0)
	{
		while(str[i])
			i++;
		if (i == 3)
			ft_set(e->list, str[1], str[2]);
		else if(i == 2)
			ft_set(e->list, str[1], "\0");
		else if(i > 3)
			ft_putstr_fd("setenv: Too many arguments.\n", 2);
		else
			print_env(e->env);
	}
	else if (str[0] && ft_strcmp(str[0], "unsetenv") == 0)
	{
		if (str[1])
			ft_unset(e->list, str);
		else
			ft_putstr_fd("unsetenv: Too few arguments.\n", 2);
	}
	else
		check_cmd2(str, e);
							// if (str)
							// 	ft_free_tab(&str);
}
