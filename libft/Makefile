# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:17:08 by stitovsk          #+#    #+#              #
#    Updated: 2023/10/06 12:56:29 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS  = -Wall -Wextra -Werror
NAME   = libft.a
FILES_C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c  ft_itoa.c \
	ft_calloc.c  ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c \
	ft_putstr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strchr.c \
	ft_strcpy.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c
FILES_O = $(FILES_C:.c=.o)

FILES_B = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c ft_lstsize_bonus.c

FILES_BO = $(FILES_B:.c=.o)
$(NAME) : $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

$(FILES_O) : $(FILES_C)
	gcc $(FLAGS) -c $(FILES_C)

all: $(NAME)

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME) $(FILES_O)

re: fclean all

bonus:
	gcc $(FLAGS) -c $(FILES_B)
	ar rcs $(NAME) $(FILES_O) $(FILES_BO)
	
.PHONY: all clean fclean re bonus
