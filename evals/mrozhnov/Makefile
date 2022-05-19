NAME=fdf
SRCS=srcs/check_keys.c srcs/handle_image.c srcs/check_reader.c \
srcs/check_rotation.c srcs/colors_issues.c srcs/draw_line.c \
srcs/drawing_issues.c srcs/file_reader.c srcs/handle_gui.c srcs/handle_mouse.c \
srcs/handle_transformation.c srcs/main.c srcs/print_map.c
OBJS=$(notdir $(SRCS:.c=.o))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
MLX=-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL \
-framework Appkit
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	@echo Compiling $(NAME)...
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	@gcc $(FLAGS) $(INCLUDES) $(MLX) -o $(NAME) $(OBJS) libft/libft.a
	@echo $(NAME) compiled succesfully!

clean:
	@/bin/rm -f $(OBJS)
	@make -C libft/ clean
	@echo Clean successful!

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo Fclean successful!

re: fclean all
