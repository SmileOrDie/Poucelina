/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 10:31:50 by shamdani          #+#    #+#             */
/*   Updated: 2015/09/28 20:09:34 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	char			*var;
	char			*value;
	int				nb;
	struct s_list	*next;
}					t_list;

typedef struct		s_env
{
	char			**env;
	char			*prompt;
	char			*shell;
	t_list			*list;
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
void				check_cmd(char *line, t_env *e);
char				*pathsys(const char *str, t_env *e);
void				ft_init(t_env *e, char **env);
void				ft_cd(char *str, t_env *e);
void				safe_free(void *ptr);
void				ft_exit(char **str);

#endif
