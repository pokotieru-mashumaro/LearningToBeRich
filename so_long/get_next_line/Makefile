NAME = get_next_line.a

SRCS =	get_next_line.c \
		get_next_line_utils.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar -rc $(NAME) $(OBJ)

.c.o:
		@cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJ) 

fclean: clean
		rm -f $(NAME)

re :	fclean all
	
.PHONY: all clean fclean re 
