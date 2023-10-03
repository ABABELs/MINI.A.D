# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:27:08 by dilovancand       #+#    #+#              #
#    Updated: 2023/10/03 13:19:02 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SOURCES = src/minishell.c src/signal_handler.c \
			src/ft_path_finder.c src/ft_path_finder_utils.c src/ft_parsing_utils.c \
			src/ft_minisplit.c src/ft_minisplit_utils.c src/ft_minisplit_count.c \
			src/ft_minialloc.c src/ft_clean_cmd.c src/ft_redirection.c src/ft_redirection_utils.c \
			src/ft_prepforexec.c src/ft_heredoc.c src/ft_heredoc_utils.c \
			src/BUILTINS/cd.c src/BUILTINS/echo.c src/BUILTINS/env.c src/BUILTINS/exit.c src/BUILTINS/export.c \
			src/BUILTINS/pwd.c src/BUILTINS/unset.c src/BUILTINS/builtins_utils.c \
			src/PIPEX/pipe.c src/PIPEX/print_list.c src/PIPEX/pipe_setup.c src/PIPEX/pipe_utils.c \
			src/ft_error.c src/ft_print_error_msg.c \
			src/free/freeing.c src/ft_open.c \
			src/ft_env.c \
			src/ft_parsing_utils_more.c \
			
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_LIB = inc/libft/libft.a
INC_DIR = inc/
READLINE = $(shell brew --prefix readline)
RL_INC = -I $(READLINE)/include
RL_LIB = -L $(READLINE)/lib -lreadline

all: ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@  $(RL_INC) -I $(INC_DIR)

${NAME}: ${OBJECTS}
	make -C inc/libft
	$(CC) $(CFLAGS) -o ${NAME} ${OBJECTS} ${LIBFT_LIB} ${RL_LIB}

clean:
	make -C inc/libft clean
	rm -f ${OBJECTS}
	
fclean: clean
	make -C inc/libft fclean
	rm -f ${NAME}

re: fclean all
