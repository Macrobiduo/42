CC= cc
NAME= pipex
FLAGS= -Wall -Wextra -Werror
SRC= pipex.c ft_utils.c	ft_frees.c
OBJ= $(SRC:.c=.o)
OBJDIR = obj/
OBJS= $(addprefix $(OBJDIR), $(OBJ))

all:	$(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(SRC) $(MLX) $(FLAGS) -o $(NAME)
	mkdir obj
	mv $(SRC:.c=.o) obj

clean:
	make clean -C libft/ 
	rm -f $(OBJS)
	rm -rf obj
	
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
re: fclean all
	make re -C libft/

.PHONY: all clean fclean re