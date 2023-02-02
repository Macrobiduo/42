CC=cc
NAME=fractol
FLAGS=-Wall -Wextra -Werror
MLX=minilibx-linux/libmlx.a -lX11 -lXext -lm
SRC=main.c
OBJ= $(SRC:.c=.o)

all:	$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MLX) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re:
	fclean all

.PHONY: all clean fclean re