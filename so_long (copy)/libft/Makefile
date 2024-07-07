# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:17:08 by stitovsk          #+#    #+#              #
#    Updated: 2024/06/11 22:05:42 by svetameanss      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS  = -Wall -Wextra -Werror -g3
NAME   = libft.a
CC = gcc
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c  ft_itoa.c \
	ft_calloc.c  ft_matrix_len.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c \
	ft_putstr.c ft_strdup.c ft_striteri.c \
	ft_strjoin.c ft_strchr.c ft_strcpy.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strncpy.c\
	ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c
OBJECTS = $(FILES:.c=.o)

# Colores
RESET = \033[0;m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m

BONUSES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ_BONUS = $(BONUSES:.c=.o)


$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "$(GREEN)Compiling $@...$(RESET)"

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS) $(OBJECTS)

.PHONY: all clean fclean re bonus
