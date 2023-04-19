# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:31:16 by maroy             #+#    #+#              #
#    Updated: 2023/04/19 00:09:06 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

HEADER_DIR		= includes/
HEADER_SRC		= pipex.h ft_printf.h
HEADER			= $(addprefix $(HEADER_DIR)/, $(HEADER_SRC))

MPATH_DIR		= src/
MPATH_SRC		= pipex.c
MPATH			= $(addprefix $(MPATH_DIR)/, $(MPATH_SRC))
OBJ_M 			= $(MPATH:.c=.o)


UTILS_DIR	= utils/
UTILS_FILES	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunnbr.c \
			  ft_puthex.c ft_putuphex.c ft_putpointer.c ft_strlen.c
UTILS		= $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJ_U		= $(UTILS:.c=.o)

OBJS 		= $(SRCS:.c=.o) $(UTILS_SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

%.o:	%.c $(HEADER) Makefile
			@$(CC) $(CFLAGS)  -c $< -o $@

$(NAME):	$(OBJ_M) $(OBJ_U) 
			@$(CC) $(OBJ_M) $(OBJ_U)  -o $(NAME)
			@echo "$(GREEN)$(NAME) created !$(DEFAULT)"
	
all:		$(NAME)

clean:
			@$(RM) $(OBJ_M)
			@$(RM) $(OBJ_U)
			@echo	"$(YELLOW)Obejct files deleted!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo	"$(RED)All deleted!$(DEFAULT)"

re:			fclean all

norm:
			@echo "$(DARKGRAY)norminette! $(DEFAULT)"
			norminette $(SRCS) $(UTILS_SRCS) $(HEADER)

.PHONY:		all clean fclean re norm

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DARKGRAY='\033[1;30m'
DEFAULT = \033[1;30m