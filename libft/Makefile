# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:17:08 by stitovsk          #+#    #+#              #
#    Updated: 2023/09/25 19:57:21 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS  = -Wall -Wextra -Werror
NAME   = libft.a
FILES_C = ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_isspace.c  ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c ft_strchr.c \
	ft_strcpy.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c
FILES_O = $(FILES_C:.c=.o) # вместо точка с мы поставим точка о

$(NAME) : $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

$(FILES_O) : $(FILES_C)
	gcc $(FLAGS) -c $(FILES_C)

all: $(NAME)

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
