CC= cc
NAME= so_long
FLAGS= -Wall -Wextra -Werror
MLX= minilibx-linux/libmlx.a -lX11 -lXext -lm
SRC= so_long.c ft_checks.c ft_mapbuild.c ft_moves.c ft_solong_utils.c \
	ft_solong_utils2.c ft_errors.c
OBJ= $(SRC:.c=.o)
OBJDIR = obj/
OBJS= $(addprefix $(OBJDIR), $(OBJ))

all:	$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MLX) $(FLAGS) -o $(NAME)
	mv $(SRC:.c=.o) obj

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
re:
	fclean all

.PHONY: all clean fclean re