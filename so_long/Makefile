# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 16:17:17 by stitovsk          #+#    #+#              #
#    Updated: 2024/07/14 22:14:40 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -ggdb
MLX_FLAGS = -ldl -lglfw -pthread -lm
#../MLX42/include/MLX42/MLX42.h
NAME = so_long
BON_NAME = so_long_bonus

SRC_DIR = ./src/mandatory/
BONUS_SRC_DIR = ./src/bonus/
INC_DIR = ./include/
BONUS_INC_DIR = ./include/bonus/
TEST_DIR = ./test/
BASE_BIN_DIR = ./bin/
BIN_DIR = $(BASE_BIN_DIR)mandatory/
BONUS_BIN_DIR = $(BASE_BIN_DIR)bonus/
OBJ_DIR = ./obj/

LIBFT_DIR = ./lib/libft/
LIBFT_BIN_DIR = $(LIBFT_DIR)
LIBFT_BIN = $(LIBFT_BIN_DIR)libft.a
LIBFT_INC = $(LIBFT_DIR)

FT_PRINTF_DIR = ./lib/ft_printf/
FT_PRINTF_BIN_DIR = $(FT_PRINTF_DIR)
FT_PRINTF_BIN = $(FT_PRINTF_BIN_DIR)libftprintf.a
FT_PRINTF_INC = $(FT_PRINTF_DIR)



MLX42_DIR = ./lib/MLX42/
MLX42_BIN_DIR = $(MLX42_DIR)
MLX42_BIN = $(MLX42_BIN_DIR)libmlx42.a
MLX42_INC = $(MLX42_DIR)include/MLX42/


SRC_FILES = check_elements.c \
			check_matrix.c \
			check_matrix_utils.c \
			floodfill.c \
			free_all.c \
			get_next_line_utils.c \
			get_next_line.c \
			load_elements.c \
			load_images.c \
			manage_errors.c \
			map_to_matrix.c \
			my_hook.c \
			my_keys.c \
			show_and_delete.c \
			so_long.c \
			update_game.c

SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

#Colors
RESET = \033[0;m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGNETA = \033[0;35m

# Pattern Rule to compile .c to .o
# $^ -> current name of prerequisite
# $@ -> current name of target
# $(OBJ): $(OBJ_DIR)%.o: $(addprefix $(SRC_DIR) $(SRC_FILES))

$(NAME): $(OBJ) $(LIBFT_BIN) $(FT_PRINTF_BIN) $(MLX42_BIN)
	$(CC) $(OBJ) $(LIBFT_BIN) $(MLX42_BIN) $(FT_PRINTF_BIN) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
#  gcc src/*.c libft/*.c get_next_line/*.c ft_printf/*.c MLX42/libmlx42.a -lglfw -fPIE -Wall -Werror -Wextra

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX42_INC) -I$(FT_PRINTF_INC) -c $^ -o $@
	@echo "$(BLUE)Compiling .o of $@...$(RESET)"
	
$(LIBFT_BIN):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_BIN):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42_BIN):
	$(MAKE) -C $(MLX42_DIR)

#cmake -S $(MLX42_DIR) -B $(MLX42_BIN_DIR)
#cmake --build $(MLX42_BIN_DIR) -j4

all: $(NAME)
	@echo "$(MAGNETA)$(NAME) executable...$(RESET)"