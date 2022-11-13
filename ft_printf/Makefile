CC=cc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=	ft_printf.c \
	ft_printf_util.c \
	ft_printf_util2.c \
	ft_printf_util3.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re