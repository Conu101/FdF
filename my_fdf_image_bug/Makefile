# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 16:55:49 by ctrouve           #+#    #+#              #
#    Updated: 2022/05/20 15:10:42 by ctrouve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
LIB				= ./libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -lmlx -framework OpenGL -framework AppKit
SRCS			= ./sources/draw_img.c\
				./sources/fdf_init.c\
				./sources/get_color.c\
				./sources/main.c\
				./sources/map_init.c\
				./sources/map_populate.c\
				./sources/new_point.c\
				./sources/numbers.c\
				./sources/build_coord_arrays.c\
				./sources/set_proj_param.c\
				./sources/terminate.c

# COLORS

GREEN = \033[0;32m
ORANGE = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
