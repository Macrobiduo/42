CC=cc
NAME=checker
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-o
SRC= checker_list_funct.c	ft_split.c	ft_check_utils.c	checker_utils.c	checker.c	ft_moves.c	ft_moves2.c	ft_moves3.c	get_next_line.c	get_next_line_utils.c
OBJDIR= ../obj/
OBJS= $(addprefix $(OBJDIR), $(OBJ))
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(OPTIONS) $(NAME)
	mv checker ../
	mv $(SRC:.c=.o) ../obj
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
