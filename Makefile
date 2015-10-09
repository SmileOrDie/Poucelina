# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/01 13:07:43 by shamdani          #+#    #+#              #
#    Updated: 2015/10/09 12:28:30 by shamdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_minishell

CC =		gcc #-Wall -Werror -Wextra

SRC =		main.c \
			ft_free.c \
			ft_list_to_tab.c \
			ft_print.c \
			ft_set.c \
			ft_tab_to_list.c \
			ft_unset.c \
			ft_builtins.c \
			ft_check_cmd.c \
			ft_check_path.c \
			ft_split.c \
			ft_init.c \
			interpretation/*.c \
			htable/*.c


COMPILE =	echo "\033[36mCompile --sh1-- ...."
COMPILED =	echo "\033[32mCompiled --sh1-- Successfully"
CLEAN =		echo "\033[36mClean --sh1-- ...."
CLEANED =	echo "\033[32mCleaned --sh1-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@make -C ./libft/
	@make -C ./libft/ clean
	@$(CC) -I ./interpretation -I ./htable -I ./ $(SRC) ./libft/libft.a  -o $(NAME)
	@$(COMPILED)

norme:
	@norminette $(SRC) ./list.h

clean:
	@$(CLEAN)
	@rm -f $(SRC_OBJ)
	@$(CLEANED)

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all