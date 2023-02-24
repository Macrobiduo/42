CC=cc
NAME=so_long
FLAGS=-Wall -Wextra -Werror
MLX=minilibx-linux/libmlx.a -lX11 -lXext -lm
SRC=so_long.c
OBJ= $(SRC:.c=.o)

all:	$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MLX) $(FLAGS) -o $(NAME)
	mv $(SRC:.c=.o) obj

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re:
	fclean all

.PHONY: all clean fclean re