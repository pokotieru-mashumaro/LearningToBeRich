NAME = fractol
SRC = main.c mandelbrot.c julia.c hooks.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	cc $(OBJ) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)

.c.o:
	cc -Imlxc -c $< -o $@

clean:
	rm $(OBJ)

 fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

