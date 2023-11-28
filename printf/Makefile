FLAGS  = -Wall -Wextra -Werror
NAME   = libftprintf.a
CC = gcc
FILES = ft_check_format.c ft_printf.c ft_put_int_unsign.c ft_put_int.c \
		ft_putptr.c ft_puthex.c ft_strchar.c
OBJECTS = $(FILES:.c=.o)

# Colors

RESET = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "$(MAGENTA)Compiling $@...$(RESET)"

all: $(NAME)

clean:
	@rm -f $(OBJECTS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re