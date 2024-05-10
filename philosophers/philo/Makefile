NAME = philo
INCLUDE = philo.h
CFLAGS = -Wall -Wextra -Werror

FILES = main.c init.c philo_behavior.c philo_tool.c utils.c
OBJ = $(FILES:.c=.o)

RM = rm -f

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

.c.o:
	cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re