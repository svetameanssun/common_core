# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 19:00:48 by stitovsk          #+#    #+#              #
#    Updated: 2024/06/04 20:13:39 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIBFT = libft
SRC_FILES = main.c \
		manage_cmd.c \
		manage_error.c \
		pipex.c \
		set_path.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

# Pattern rule to compile .c to .o
# $^ -> current name of prerequisite
# $@ -> current name of target
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(MAKE) -C $(LIBFT) clean
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT).a -o $(NAME)

clean:
	rm -f $(OBJ) $(LIBFT).a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re