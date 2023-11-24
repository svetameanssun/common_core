NAME = libftprintf.a
FILES = *.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror

all :$(NAME)

$(NAME): $(OBJECTS)
	@ar rsc $(NAME) $(OBJECTS)

$(OBJECTS) :$(FILES)
	@cc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS) $(NAME)

re :fclean all

.PHONY: all clean fclean re