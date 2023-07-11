# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:15:05 by jrenault          #+#    #+#              #
#    Updated: 2023/06/11 23:33:52 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: bonus all clean fclean re

NAME = libft.a

SRCS = 	free_tab_int.c ft_strlen_doublechar.c ft_swap_int.c free_tab_void.c free_tab.c ft_count.c ft_count_ul.c ft_count_unsigned.c ft_count_long.c \
		ft_putnbr_base_ul.c ft_putunbr.c ft_strncpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbr.c ft_putnbr_base.c ft_putstr.c ft_putchar.c ft_strcpy.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c ft_printf/ispercent_c.c ft_printf/ispercent_capx.c ft_printf/ispercent_d_i.c ft_printf/ispercent_p.c ft_printf/ispercent_s.c ft_printf/ispercent_u.c ft_printf/ispercent_x.c ft_printf/search_arg.c \

OBJS = ${SRCS:.c=.o}

CC = cc
FLAGS = -Wall -Wextra -Werror
SANITFLAG = -Wall -Wextra -Werror -g -fsanitize=address
HEAD = libft.h

LIB = ar rc

RM = rm -f

%.o:		%.c ${HEAD} Makefile
			${CC} ${FLAGS} -include${HEAD} -c $< -o $@

${NAME}: 	${OBJS} Makefile
			${LIB} ${NAME} ${OBJS}

sanit:		$(OBJS) main.c
			${CC} ${SANITFLAG} $(OBJS) main.c

all:		${NAME} Makefile

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
