NAME = push_swap
FLAGS = -Wall -Wextra -Werror
FILES = $(shell find src -type f -name "*.c")
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME) 

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C include clean

fclean:
	@rm -f $(OBJS) $(NAME)
	@make -C include fclean

re: fclean all

.PHONY: all clean fclean re