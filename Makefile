# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <vafleith@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:41:29 by vafleith          #+#    #+#              #
#    Updated: 2024/02/27 21:25:24 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -g3
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

SRCS = main.c draw.c events.c mandelbrot.c multibrot.c julia.c burning_ship.c \
	   view.c exit_program.c color.c init.c double_conversion.c parse_args.c \
	   utils.c handle.c display.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

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
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLXFLAGS) -lm
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
