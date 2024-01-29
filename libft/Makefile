# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:44:12 by vafleith          #+#    #+#              #
#    Updated: 2024/01/29 15:53:14 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC=cc
CFLAGS= -Wall -Wextra -Werror

LIB_H = libft.h
PRINTF_H = ft_printf.h


SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_printf.c ft_print_format.c \
			ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c	\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c


OBJECTS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS:%.c=%.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJECTS)
	@echo Building Libft
	@ar rc $(NAME) $(OBJECTS)

%.o: %.c
#@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: bonus
bonus: $(BONUS_OBJS)
	@echo Building Bonus
	@ar rc $(NAME) $(BONUS_OBJS)

.PHONY: clean
clean:
	@echo Cleaning up objects files
	@rm -f $(OBJECTS) $(BONUS_OBJS)

.PHONY: fclean
fclean: clean
		@echo Cleaning up lib
		@rm -rf $(NAME)

.PHONY: re
re: fclean all
