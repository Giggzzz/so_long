# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/29 02:04:47 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 
INCL	= -I incs
RM	= rm -f

LIBFT	= libs/libft/libft.a
MLX	= libs/mlx_linux/libmlx_Linux.a

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= so_long.c \

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(YELLOW)Compiling $(DEFAULT)$<"
	@mkdir -p $(OBJSDIR) $(OBJSDIR)/utils
	@$(CC) $(CLFAGS) $(INCL) -I/usr/include -Ilibs/mlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Creating executable..$(DEFAULT)"
	@$(CC) $(CFLAGS) $^ -Llibs/mlx_linux -lmlx_Linux -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz -o $@
	@echo "$(GREEN)--->./$@ is ready$(DEFAULT)"

$(MLX):
	@make -C libs/mlx_linux

$(LIBFT):
	@make -C libs/libft

clean:
	@$(RM) -r $(OBJSDIR)
	@make clean -C libs/libft
	#@make clean -C libs/mlx_linux
	@echo "$(RED)!! Object files deleted !!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	#@make fclean -C libs/libft
	#@make clean -C libs/mlx_linux
	@echo "$(RED)!! ./$(NAME) deleted !!$(DEFAULT)"

bonus: re

re: fclean all

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
