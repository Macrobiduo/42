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
	$(CC) -g $(SRC) $(MLX) $(FLAGS) libft/libft.a -o $(NAME)
	mkdir obj
	mv $(SRC:.c=.o) obj
	@echo pipex compiled!

clean:
	make clean -C libft/ 
	rm -f $(OBJS)
	rm -rf obj
	@echo pipex objects cleaned
	
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	@echo pipex compiled files cleaned

re: fclean all
	make re -C libft/
	@echo make re redone!

.PHONY: all clean fclean re

.SILENT: