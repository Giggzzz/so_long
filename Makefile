# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/04/04 10:57:02 by gudias           ###   ########.fr        #
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
	#CFLAGS += -D OS_DARWIN
else ifeq ($(OS),Linux)
	MLX_DIR	= libs/mlx_linux
	MLX		= libs/mlx_linux/libmlx_Linux.a
	MLX_INC	= -I/usr/include -Ilibs/mlx_linux -O3
	MLX_FLG	= -Llibs/mlx_linux -lmlx_Linux -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz
	#CFLAGS += -D OS_LINUX
endif

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= so_long.c events.c errors.c check_map.c draw_map.c player.c

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(YELLOW)Compiling $(DEFAULT)$<"
	@mkdir -p $(OBJSDIR)
	@$(CC) $(CLFAGS) $(INCL) $(MLX_INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Creating executable..$(DEFAULT)"
	@$(CC) $(CFLAGS) $^ $(MLX_FLG) -o $@
	@echo "$(GREEN)---> ./$@ is ready$(DEFAULT)"

$(MLX):
	@echo "$(YELLOW)Preparing MiniLibX..$(DEFAULT)"
	@make -C $(MLX_DIR) 1>/dev/null 2>/dev/null
	@echo "$(CYAN)---> MiniLibX ready$(DEFAULT)"

$(LIBFT):
	@echo "$(YELLOW)Preparing Libft..$(DEFAULT)"
	@make -C libs/libft 1>/dev/null 2>/dev/null
	@echo "$(CYAN)---> Libft ready$(DEFAULT)"

clean:
	@$(RM) -r $(OBJSDIR)
	@echo "$(RED)Removed $(CYAN)objs/$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(CYAN)./$(NAME)$(DEFAULT)"

libclean: 
	@make fclean -C libs/libft 1>/dev/null 2>/dev/null
	@echo "$(RED)Removed $(CYAN)Libft$(DEFAULT)"
	@make clean -C $(MLX_DIR) 1>/dev/null 2>/dev/null
	@echo "$(RED)Removed $(CYAN)MiniLibX$(DEFAULT)"

fullclean: fclean libclean

bonus: re

re: fclean all

.PHONY: all clean fclean re bonus libclean fullclean

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
DEFAULT = \033[0m
