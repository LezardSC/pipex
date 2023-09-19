# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 08:46:55 by jrenault          #+#    #+#              #
#    Updated: 2023/07/11 17:32:28 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all clear mkbuild lib clean fclean re bonus

NAME					= pipex

BUILD_DIR				= build/
BUILD_DIR_BONUS			= build/
	
HEADER_DIR				= header/
HEADER_FILE				= pipex.h
HEADERS_WITH_PATH		= $(addprefix $(HEADER_DIR),$(HEADER_FILE))
HEADERS_WITH_PATH_BONUS	= $(addprefix $(HEADER_DIR),$(HEADER_FILE_BONUS))

DIR						= src/
SRC			 			= 	main.c \
							pipex.c \
							pipex_utils.c \
							sub_functions.c \

DIR_BONUS				= src_bonus/
SRC_BONUS			 	= 	main_bonus.c \
							pipex_bonus.c \
							pipex_utils_bonus.c \
							sub_functions_bonus.c \

OBJECTS			    	= ${addprefix ${BUILD_DIR},${SRC:.c=.o}}
OBJECTS_BONUS		   	= ${addprefix ${BUILD_DIR_BONUS},${SRC_BONUS:.c=.o}}

LIBFT					= libft.a
LIB_DIR					= libft/
	
GCC						= cc
CFLAGS					= -Wall -Wextra -Werror -g3

RM 						= rm -rf
CLEAR					= clear


$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADERS_WITH_PATH} Makefile
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(BUILD_DIR_BONUS)%.o:	$(DIR_BONUS)%.c ${HEADERS_WITH_PATH_BONUS} Makefile
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@


all: 					mkbuild  $(HEADER_DIR)
						$(MAKE) lib
						$(MAKE) $(NAME)

mkbuild:
						mkdir -p build

clear:
						$(CLEAR)

$(NAME): 				$(OBJECTS) lib $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)

bonus:					$(OBJECTS_BONUS) lib $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME) $(LIB_DIR)$(LIBFT)

lib:
						make FLAGS="-Wall -Wextra -Werror -g3" -C $(LIB_DIR)
						
clean:					
						${RM} $(OBJECTS) $(OBJECTS_BONUS)
						make clean -C $(LIB_DIR)
						${RM} $(BUILD_DIR) $(BUILD_DIR_BONUS)

fclean:					clean
						${RM} ${NAME}
						make fclean -C $(LIB_DIR)

re:						fclean
						$(MAKE) all