# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 22:51:43 by pmeising          #+#    #+#              #
#    Updated: 2022/08/15 22:55:11 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall -fsanitize=address

RM			:= rm -f

HEADER		:= pipex.h

SRCS		:= main.c ft_syntax_check.c ft_pipex.c ft_parent_process.c \
			ft_child_process.c \

OBJS		:= ${SRCS:.c=.o}

LIBFT = ./libft/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			make all -C ./libft_lib


$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
