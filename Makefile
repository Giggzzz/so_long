# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/30 01:11:57 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 
INCL	= -I incs
RM		= rm -f

LIBFT	= libs/libft/libft.a

OS := $(shell uname)
ifeq ($(OS),Darwin)
	MLX_DIR		= libs/mlx_mac
	MLX		= libs/mlx_mac/libmlx.a
	MLX_INC = -Ilibs/mlx_mac
	MLX_FLG = -Llibs/mlx_mac -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS),Linux)
	MLX_DIR	= libs/mlx_linux
	MLX		= libs/mlx_linux/libmlx_Linux.a
	MLX_INC	= -I/usr/include -Ilibs/mlx_linux -O3
	MLX_FLG	= -Llibs/mlx_linux -lmlx_Linux -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz
endif

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= so_long.c events.c

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(YELLOW)Compiling $(DEFAULT)$<"
	@mkdir -p $(OBJSDIR)
	$(CC) $(CLFAGS) $(INCL) $(MLX_INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Creating executable..$(DEFAULT)"
	$(CC) $(CFLAGS) $^ $(MLX_FLG) -o $@
	@echo "$(GREEN)--->./$@ is ready$(DEFAULT)"

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C libs/libft

clean:
	@$(RM) -r $(OBJSDIR)
	@make clean -C libs/libft
	#@make clean -C $(MLX_DIR)
	@echo "$(RED)!! Object files deleted !!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	#@make fclean -C libs/libft
	#@make clean -C $(MLX_DIR)
	@echo "$(RED)!! ./$(NAME) deleted !!$(DEFAULT)"

bonus: re

re: fclean all

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
