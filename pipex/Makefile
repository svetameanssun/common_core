# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 19:00:48 by stitovsk          #+#    #+#              #
#    Updated: 2024/06/06 15:38:26 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = pipex
LIBFT = libft
SRC_FILES = main.c \
		manage_cmd.c \
		manage_error.c \
		pipex.c \
		set_path.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

# Colores
RESET = \033[0;m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m

# Pattern rule to compile .c to .o
# $^ -> current name of prerequisite
# $@ -> current name of target
%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "$(BLUE)Compiling $@...$(RESET)"
all: $(NAME)
	@echo "$(MAGENTA)$(NAME) executable created...$(RESET)"


$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@mv $(LIBFT)/$(LIBFT).a $(LIBFT).a
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT).a -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ) $(LIBFT).a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re