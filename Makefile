# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 17:27:19 by gudias            #+#    #+#              #
#    Updated: 2022/03/28 02:18:20 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 
INCL	= -I incs
RM	= rm -f

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS	= so_long.c \
	  #$(addprefix utils/, )

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(YELLOW)Compiling $(DEFAULT)$<"
	@mkdir -p $(OBJSDIR) $(OBJSDIR)/utils
	$(CC) $(CLFAGS) $(INCL) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating executable..$(DEFAULT)"
	$(CC) $(CFLAGS) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@
	@echo "$(GREEN)--->./$@ is ready$(DEFAULT)"

clean:
	@$(RM) -r $(OBJSDIR)
	@echo "$(RED)!! Object files deleted !!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)!! ./$(NAME) deleted !!$(DEFAULT)"

bonus: re

re: fclean all

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
