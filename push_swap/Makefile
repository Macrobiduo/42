CC=cc
NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-o
SRC=	ft_analysis.c	ft_checks.c	ft_evaluation.c		ft_list_func.c		ft_list_func2.c \
		ft_moves.c		ft_moves2.c	ft_moves3.c		push_swap.c  ft_split.c  ft_utils.c\

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(OPTIONS) $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C my_checker
	
fclean: clean
	rm -f $(NAME)
	make fclean -C my_checker

re: fclean all	

bonus:
	make -C my_checker

.PHONY: clean fclean all re bonus
