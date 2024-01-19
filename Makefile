# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 08:59:16 by vafleith          #+#    #+#              #
#    Updated: 2024/01/19 11:19:32 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

SRC_DIR = src
OBJ_DIR = build
INC = include
PATH_MLX = minilibx-linux
LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra
#CFLAGS += -Werror
MLXFLAG = -lmlx -lXext -lX11

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/draw.c $(SRC_DIR)/event.c $(SRC_DIR)/colors.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT) -L$(PATH_MLX) $(MLXFLAG) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
#@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC) $(MLXFLAG) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@echo Object files cleaned
#@make -C $(LIBFT) clean

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)
	@echo Exec files cleaned
#@make -c $(LIBFT) fclean

.PHONY: re
re: fclean all

