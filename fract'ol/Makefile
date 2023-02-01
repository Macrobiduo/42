CC=cc
NAME=fractol
FLAGS=-Wall -Wextra -Werror
SRC=
OPTIONS= -o
OBJ= $(SRC:.c=.o)

all:	$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) $(OPTION) $(NAME)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re:
	fclean all
.PHONY all clean fclean re