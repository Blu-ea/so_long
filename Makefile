# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 04:32:58 by amiguez           #+#    #+#              #
#    Updated: 2022/04/25 16:14:27 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

# /////////////////////////////////

LST_SRCS	:=	main.c\
				parsec.c\
				debug.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	so_long.h
AR_LIBFT	:=	libft.a
AR_MLIBX	:=	libmlx.a

# /////////////////////////////////

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	.
DIR_LIBFT	:=	libft
DIR_MLIBX	:=	minilibx_opengl_20191021

# /////////////////////////////////

SRCS		:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS		:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS		:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))
LIBFT		:=	$(addprefix $(DIR_LIBFT)/, $(AR_LIBFT))
MLIBX		:=	$(addprefix $(DIR_MLIBX)/, $(AR_MLIBX))

# /////////////////////////////////


CC			:=	gcc
CFLAGS		:= #-Wall -Werror -Wextra

# /////////////////////////////////

ERASE		:=	\033[2K\r
GREY		:=	\033[30m
RED			:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
PINK		:=	\033[35m
CYAN		:=	\033[36m
WHITE		:=	\033[37m
BOLD		:=	\033[1m
UNDER		:=	\033[4m
SUR			:=	\033[7m
END			:=	\033[0m

# /////////////////////////////////

NORMITEST	= 
NORMINETTE	=	$(shell norminette $(SRCS) $(INCS) | grep -i 'Error!')

# /////////////////////////////////

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(MLIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLIBX) -framework OpenGL -framework AppKit -v -o $(NAME)

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(DIR_OBJS)	:
	mkdir -p $@

$(LIBFT)	:
	make -C $(DIR_LIBFT)

$(MLIBX)	:
	make -C $(DIR_MLIBX)

# /////////////////////////////////

clean	:
	rm -rf $(DIR_OBJS)
	make -C $(DIR_LIBFT) clean
	make -C $(DIR_MLIBX) clean

fclean	: clean
	rm -rf $(NAME)
	make -C $(DIR_LIBFT) fclean

re		: fclean all
	make -C $(DIR_LIBFT) re
	make -C $(DIR_MLIBX) re

.PHONY	: all clean fclean re $(LIBFT) $(MLIBX)
# .SILENT :