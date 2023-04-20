CC = cc -g -pthread
NAME = philo
SRC = philo.c philo_utils.c philo_frees.c philo_init.c philo_dinner.c philo_check.c
FLAG = -Wall -Wextra -Werror
OBJ= $(SRC:.c=.o)
OBJDIR = obj/
OBJS= $(addprefix $(OBJDIR), $(OBJ))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)
	mkdir obj
	mv $(SRC:.c=.o) obj
	@echo philo compiled!
clean:
	rm -f $(OBJ)
	rm -rf obj
	@echo philo objects cleaned!

fclean: clean
	rm -f $(NAME)
	@echo philo compiled files cleaned!

re: fclean all
	@echo make re redone!

.PHONY: all clean fclean re
.SILENT: