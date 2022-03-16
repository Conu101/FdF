# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:22:54 by ctrouve           #+#    #+#              #
#    Updated: 2022/03/16 14:00:59 by ctrouve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tutorial

SOURCES = tutorial.c draw_line.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra #-Werror
LINKS = -I libft -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

# COLORS
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

$(NAME): $(OBJECTS)
	@gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
	@echo "$(NAME): $(GREEN) $(NAME) was compiled$(RESET)"

clean:
	@rm -rf $(OBJECTS)
	@echo "$(NAME): $(YELLOW) object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(YELLOW)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE)
