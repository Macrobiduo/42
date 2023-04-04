CC= cc
NAME= pipex
FLAGS= -Wall -Wextra -Werror
SRC= pipex.c	ft_utils.c	ft_split.c	ft_utils2.c
OBJ= $(SRC:.c=.o)
OBJDIR = obj/
OBJS= $(addprefix $(OBJDIR), $(OBJ))

all:	$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MLX) $(FLAGS) -o $(NAME)
	mkdir obj
	mv $(SRC:.c=.o) obj

clean:
	rm -f $(OBJS)
	rm -rf obj
	
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re