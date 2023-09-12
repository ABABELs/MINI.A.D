# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:27:08 by dilovancand       #+#    #+#              #
#    Updated: 2023/09/12 18:05:21 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SOURCES = src/minishell.c src/signal_handler.c src/ft_path_finder.c src/ft_path_finder_utils.c src/ft_parsing_utils.c src/ft_minisplit_utils.c src/ft_minialloc.c src/ft_clean_cmd.c src/ft_redirection.c src/ft_minisplit.c
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
