# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 18:13:15 by dcandan           #+#    #+#              #
#    Updated: 2023/03/23 14:48:09 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		 ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		 ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
		 ft_toupper.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
		 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		 ft_putendl_fd.c ft_itoa.c ft_print.c ft_printhexa.c ft_printstr.c \
		 ft_printunsigned.c ft_printvoid.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		 ft_lstmap.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line.c \
		 get_next_line/get_next_line_utils_bonus.c get_next_line/get_next_line_utils.c \

OBJECTS = ${SOURCE:.c=.o}

all: ${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all
