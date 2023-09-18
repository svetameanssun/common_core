# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:17:08 by stitovsk          #+#    #+#              #
#    Updated: 2023/09/14 15:17:57 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS  = -Wall -Wextra -Werror
NAME   = libft.a
FILES_C = ft_abs.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_isspace.c ft_memcpy.c ft_memset.c ft_memmove.c ft_bzero.c \
	ft_putchar.c ft_putstr.c ft_strchr ft_strcpy.c \
	ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_tolower.c ft_toupper.c
FILES_O = $(FILES_C:.c=.o) # вместо точка с мы поставим точка о

$(NAME) : $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

$(FILES_O) : $(FILES_C)
	gcc $(FLAGS) -c $(FILES_C)

all: $(NAME)

fclean:
	rm *.o libft.a