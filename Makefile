# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 22:51:43 by pmeising          #+#    #+#              #
#    Updated: 2022/09/25 18:38:44 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

BONUS		:= pipex_bonus

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall -fsanitize=address

RM			:= rm -f

HEADER		:= ./inc/pipex.h

SRC_DIR		:= ./src/

SRC_DIR_B	:= ./src_bonus/

SRCS		:=	${SRC_DIR}main.c ${SRC_DIR}ft_syntax_check.c ${SRC_DIR}ft_pipex.c \
				${SRC_DIR}ft_parent_process.c ${SRC_DIR}ft_child_process.c \
				${SRC_DIR}ft_error.c ${SRC_DIR}ft_helper.c ${SRC_DIR}ft_helper2.c \

B_SRCS		:=	${SRC_DIR_B}main_bonus.c ${SRC_DIR}ft_syntax_check.c \
				${SRC_DIR_B}ft_pipex_bonus.c ${SRC_DIR}ft_error.c ${SRC_DIR}ft_helper.c \
				${SRC_DIR}ft_helper2.c ${SRC_DIR_B}ft_heredoc.c ${SRC_DIR_B}ft_pipex_heredoc.c \

OBJS		:= ${SRCS:.c=.o}

B_OBJS		:= ${B_SRCS:.c=.o}

LIBFT 		:= ./libft/libft.a

#___________________________###_______________________________________________________#
#	colours

C_GREEN		:= \033[0;92m
C_YELLOW	:= \033[0;93m
C_BLUE		:= \033[0;94m
C_STD		:= \033[0;39m
C_GREY		:= \033[2;30m
C_RED		:= \033[31m

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			@echo "$(C_GREY)~"
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			@echo "$(C_BLUE) Compiling libft...$(C_STD)"
			make all -C ./libft_lib
			@echo "\n$(C_GREEN) Compilation complete\n $(C_STD)"

$(BONUS):	$(LIBFT) $(B_OBJS)
			@echo "$(C_BLUE)Making bonus: $(C_STD)"
			$(CC) $(B_OBJS) $(LIBFT) -o $(NAME)
			@echo "$(C_GREEN)<<.........................compilation complete................................>>$(C_STD)"
			@echo "\n$(C_BLUE)Syntax:$(C_STD) ./pipex file1 cmd1 cmd2 file2\n"
			@echo "\n$(C_BLUE)Bonus_Syntax:$(C_STD)./pipex file1 cmd1 cmd2 cmd3 cmd4 ... cmdn file2\nBehaves like: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2"
			@echo "\n$(C_BLUE)Bonus_Syntax:$(C_STD)./pipex here_doc DELIMITER cmd cmd1 file2\nBehaves like: cmd << LIMITER | cmd1 >> file\n"


$(NAME):	$(LIBFT) $(OBJS)
			@echo "$(C_BLUE)Making o-files and compiling program.$(C_STD)"
			$(CC) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "$(C_GREEN)<<.........................compilation complete................................>>$(C_STD)"

bonus:		${BONUS}

re:			fclean all

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS)
