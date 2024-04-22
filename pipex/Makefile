NAME = pipex
INCLUDE = includes/pipex.h
CFLAGS	=	-Wall -Wextra -Werror
RM			=	rm -f

FOLDER = src
ITEM_FOLDER = src/items
LIBFT_FOLDER = src/libft

FUNCTIONS	=	$(FOLDER)/push_swap.c $(FOLDER)/init_dst.c $(FOLDER)/ps_error.c $(FOLDER)/algo.c 

all: $(NAME)

$(NAME):
	cc $(CFLAGS) -I$(INCLUDE) $(FUNCTIONS) -o pipex

fsanitize:
	cc $(CFLAGS) -g -fsanitize=address -I$(INCLUDE) $(FUNCTIONS) -o pipex


clean:
	$(RM) push_swap

fclean: clean
	$(RM) push_swap

re: clean all

.PHONY: all clean fclean re