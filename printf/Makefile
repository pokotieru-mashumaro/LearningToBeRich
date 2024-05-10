NAME = libftprintf.a
INCLUDE = printf.h
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c c_s_p_d_u.c x_upperx_percent.c put_series.c 

OBJ = $(FILES:.c=.o)

RM = rm -f

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

.c.o:
	cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re