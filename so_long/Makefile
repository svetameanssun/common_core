# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 16:17:17 by stitovsk          #+#    #+#              #
#    Updated: 2024/07/15 21:08:01 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -ggdb
MLX_FLAGS = -ldl -lglfw -pthread -lm
NAME = so_long
NAME_BONUS = so_long_bonus

SRC_DIR = ./src/mandatory/
SRC_DIR_BONUS = ./src/bonus/

INC_DIR = ./include/
INC_DIR_BONUS = ./include/

BASE_BIN_DIR = ./bin/

BIN_DIR = $(BASE_BIN_DIR)mandatory/
BIN_DIR_BONUS = $(BASE_BIN_DIR)bonus/

OBJ_DIR = ./obj/mandatory/
OBJ_DIR_BONUS = ./obj/bonus/

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

# SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

SRC_BONUS_FILES = check_elements_bonus.c \
			check_matrix_bonus.c \
			check_matrix_utils_bonus.c \
			floodfill_bonus.c \
			free_all_bonus.c \
			get_next_line_utils_bonus.c \
			get_next_line_bonus.c \
			load_elements_bonus.c \
			load_images_bonus.c \
			manage_errors_bonus.c \
			map_to_matrix_bonus.c \
			my_hook_bonus.c \
			my_keys_bonus.c \
			show_and_delete_bonus.c \
			so_long_bonus.c \
			update_game_bonus.c

OBJ_BONUS = $(SRC_BONUS_FILES:%.c=$(OBJ_DIR_BONUS)%.o)

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
	@$(CC) $(OBJ) $(LIBFT_BIN) $(MLX42_BIN) $(FT_PRINTF_BIN) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
#  gcc src/*.c libft/*.c get_next_line/*.c ft_printf/*.c MLX42/libmlx42.a -lglfw -fPIE -Wall -Werror -Wextra

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX42_INC) -I$(FT_PRINTF_INC) -c $^ -o $@
	@echo "$(BLUE)Compiling .o of $@...$(RESET)"
	
$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_BIN) $(FT_PRINTF_BIN) $(MLX42_BIN)
	@$(CC) $(OBJ_BONUS) $(LIBFT_BIN) $(MLX42_BIN) $(FT_PRINTF_BIN) $(MLX_FLAGS) $(CFLAGS) -o $(NAME_BONUS)

$(OBJ_BONUS): $(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX42_INC) -I$(FT_PRINTF_INC) -c $^ -o $@
	@echo "$(RED)Compiling .o of $@...$(RESET)"

$(LIBFT_BIN):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_BIN):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42_BIN):
	@$(MAKE) -C $(MLX42_DIR)
	
#cmake -S $(MLX42_DIR) -B $(MLX42_BIN_DIR)
#cmake --build $(MLX42_BIN_DIR) -j4

bonus: $(NAME_BONUS)

all: $(NAME)
	@echo "$(MAGNETA)$(NAME) executable...$(RESET)"

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -s -C $(MLX42_DIR) clean
	@-rm -f $(OBJ)
	@-rm -f $(OBJ_BONUS)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -s -C $(MLX42_DIR) fclean
	@-rm -f so_long
	@-rm -f so_long_bonus

re: fclean all

.PHONY: all clean fclean re
