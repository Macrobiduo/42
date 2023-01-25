CC=cc
NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=	ft_analysis.c	ft_checks.c		ft_evaluation.c		ft_list_func.c		ft_list_func2.c \
		ft_moves.c		ft_moves2.c		ft_moves3.c			push_swap.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC) -o $(NAME)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re