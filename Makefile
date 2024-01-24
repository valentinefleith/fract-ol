# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:41:29 by vafleith          #+#    #+#              #
#    Updated: 2024/01/24 15:19:01 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc
CFLAGS = -Wall -Wextra
#CFLAGS += -Werror

MLX_PATH = minilibx-linux
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)/$(MLX_NAME)
MLXFLAGS = -lXext -lX11

INC = -Iinclude -Ilibft -I$(MLX_PATH)

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/draw.c $(SRC_DIR)/events.c \
	   $(SRC_DIR)/colors.c $(SRC_DIR)/mandelbrot.c

OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(MLX) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MLX"
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) $(MLXFLAGS)
	@echo "Fract-ol ready."

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_PATH)

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
