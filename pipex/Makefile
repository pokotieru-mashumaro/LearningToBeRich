NAME = pipex
INCLUDE = includes/pipex.h
CFLAGS	=	-Wall -Wextra -Werror
RM			=	rm -f

FOLDER = src
ITEM_FOLDER = src/items
LIBFT_FOLDER = src/libft

FUNCTIONS	=	$(FOLDER)/pipex.c $(FOLDER)/excecute.c $(FOLDER)/utils.c $(FOLDER)/ft_split.c

all: $(NAME)

$(NAME):
	cc -I$(INCLUDE) $(FUNCTIONS) -o pipex

fsanitize:
	cc $(CFLAGS) -g -fsanitize=address -I$(INCLUDE) $(FUNCTIONS) -o pipex


clean:
	$(RM) pipex

fclean: clean
	$(RM) pipex

re: clean all

.PHONY: all clean fclean re
