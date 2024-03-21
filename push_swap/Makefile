NAME = push_swap
ARCHIVE = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/ft_printf.a

PUSH_SWAP_FILES = push_swap \
						operations \
						str_to_int_arr \

SRC_DIR = ./src/
PUSH_SWAP_SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(PUSH_SWAP_FILES)))

OBJS_DIR = ./src/
PUSH_SWAP_OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .c, $(PUSH_SWAP_FILES)))

%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(FT_PRINTF) $(PUSH_SWAP_OBJS)
	@$(CC) $(FLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(FT_PRINTF):
	@make -C $(LIBFT_PATH) all

all: $(NAME)

clean:
	@rm -f $(PUSH_SWAP_OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF) fclean

re: fclean all