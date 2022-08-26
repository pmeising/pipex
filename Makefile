# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 22:51:43 by pmeising          #+#    #+#              #
#    Updated: 2022/08/26 13:55:34 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

BONUS		:= pipex_bonus

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall -fsanitize=address

RM			:= rm -f

HEADER		:= pipex.h

SRCS		:= main.c ft_syntax_check.c ft_pipex.c ft_parent_process.c \
			ft_child_process.c ft_error.c ft_helper.c ft_helper2.c \

B_SRCS		:= ./bonus/main_bonus.c ft_syntax_check.c \
				./bonus/ft_pipex_bonus.c ft_error.c ft_helper.c ft_helper2.c \

OBJS		:= ${SRCS:.c=.o}

B_OBJS		:= ${B_SRCS:.c=.o}

LIBFT 		:= ./libft/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			make all -C ./libft_lib

$(BONUS):	$(LIBFT) $(B_OBJS)
			$(CC) $(B_OBJS) $(LIBFT) -o $(NAME)


$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) -o $(NAME)

bonus:		${BONUS}

re:			fclean all

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS)
