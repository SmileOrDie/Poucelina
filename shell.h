/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 12:11:37 by shamdani          #+#    #+#             */
/*   Updated: 2015/10/09 12:11:44 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#define ERROR 0
#define NO_ERROR 1
#define TRUE 0
#define FALSE 1

#define NORMAL_EXIT 0
#define ERROR_EXIT -1

# define LINE_SIZE 4096

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <htable.h>

typedef struct		s_list
{
	char			*var;
	char			*value;
	int				nb;
	struct s_list	*next;
}					t_list;



typedef struct		s_env
{
	size_t			len;
	size_t			pos;
	size_t			start;
	char			line[_POSIX2_LINE_MAX];
	char			buffer[_POSIX2_LINE_MAX];
	char			interprete[_POSIX2_LINE_MAX];
	int				argc;
	char			*argv[_POSIX_ARG_MAX];
	hashtable_t		*local_variables;

	char			pwd[_POSIX_PATH_MAX];
	char			home[_POSIX_PATH_MAX];
	size_t			pwd_len;
	size_t			home_len;

	t_list			*list;
	char			*prompt;
	char			*shell;
	char			**env;

	char			*argv_pool[_POSIX_ARG_MAX];
	size_t			argv_pool_size;

	char			error;
	char			last_token;
	char			pursue;
	char			last_char;
}					t_env;


char				**ft_split(char *str);
void				ft_unset(t_list *list, char **str);
void				ft_set(t_list *list, char *var, char *val);
void				ft_free_tab(char ***tab);
void				free_elem(t_list **elem);
void				print_list(t_list *list);
void				print_env(char **env);
char				**conv_lst(t_list *list);
t_list				*ft_create_list(char **env);
char				*ft_check_var(t_list *list, char *var);
void				check_cmd(t_env *e);
char				*pathsys(const char *str, t_env *e);
t_env				*ft_init(char **env);
void				ft_cd(char *str, t_env *e);
void				safe_free(void *ptr);
void				ft_exit(char **str);

# include <interprete.h>

#endif
