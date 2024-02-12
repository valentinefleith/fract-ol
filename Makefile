# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:41:29 by vafleith          #+#    #+#              #
#    Updated: 2024/02/12 23:09:42 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc
CFLAGS = -Wall -Wextra -g3 -lm
CFLAGS += -Werror

MLX_PATH = minilibx-linux
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)/$(MLX_NAME)
MLXFLAGS = -lXext -lX11

LIBFT_PATH = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)

INC = -Iinclude -Ilibft -I$(MLX_PATH)

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/draw.c $(SRC_DIR)/events.c \
	   $(SRC_DIR)/mandelbrot.c $(SRC_DIR)/julia.c $(SRC_DIR)/view.c \
	   $(SRC_DIR)/display.c $(SRC_DIR)/burning_ship.c $(SRC_DIR)/exit_program.c \
	   $(SRC_DIR)/color.c $(SRC_DIR)/init.c

OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MLX"
	@make -sC $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@echo "Making Libft"
	@make -sC $(LIBFT_PATH) > /dev/null

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLXFLAGS)
	@echo "Fract-ol ready."

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_PATH) > /dev/null
	@make clean -C $(LIBFT_PATH) > /dev/null

.PHONY: fclean
fclean: clean
	@make clean -C $(MLX_PATH) > /dev/null
	@make fclean -C $(LIBFT_PATH) > /dev/null
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
