# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claprand <claprand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 11:32:19 by claprand          #+#    #+#              #
#    Updated: 2025/01/07 13:01:18 by claprand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
DEF_COLOR		= \033[0;39m
GREY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ORANGE			= \033[38;5;214m

NAME = cub3D

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a

CC = cc
INCLUDES = -I ./libft/include -I ./include -I$(MLX_DIR)
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)  -L$(MLX_DIR) -Lmlx -lmlx -L/usr/X11/lib -lX11 -lXext -lm -O3 -I/usr/X11/include
MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -L/usr/X11/lib -lX11 -lXext
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MAKEFLAGS += --no-print-directory

SRCS_DIR = ./srcs
OBJS_DIR = ./obj
SRC = 	main.c \
		utils/error.c \
		game/game.c \
		parsing/parse_arg.c \
		parsing/parsing.c \
		parsing/parsing_1.c \
		parsing/parsing_2.c \
		parsing/parsing_3.c \
		parsing/utils.c \
		cast_map/cast_map.c \
		cast_map/cast_map_1.c \
		utils/free.c \
		init/init_data.c \
		init/init.c \
		init/init_1.c \
		raycasting/draw_wall.c \
		raycasting/key_hook.c \
		raycasting/raycasting.c \
		raycasting/raycasting_1.c \
		minimap/minimap.c \
		minimap/minimap_utils.c \
	
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJ = $(SRC:.c=.o)	
OBJS = $(patsubst %(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)
MLX 	= mlx/libmlx_Linux.a
	
all: $(NAME)

$(LIBFT):
	@echo "$(GREY)Compiling libft...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	git clone https://github.com/42Paris/minilibx-linux.git mlx
	make -C mlx

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	@echo "$(ORANGE)Compiling $(NAME) with objects:\n$(OBJS)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(GREEN)$(NAME) has been created.$(DEF_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "$(ORANGE)Compiling $< to $@$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(MAGENTA)Cleaning up...$(DEF_COLOR)"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Performing full clean...$(DEF_COLOR)"
	@rm -rf $(NAME) mlx
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for cub3d$(DEF_COLOR)"

.PHONY: all clean fclean re