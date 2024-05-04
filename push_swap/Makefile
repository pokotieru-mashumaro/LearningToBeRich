NAME = push_swap
INCLUDE = includes/push_swap.h
CFLAGS	=	-Wall -Wextra -Werror
RM			=	rm -f

FOLDER = src
ITEM_FOLDER = src/items
LIBFT_FOLDER = src/libft

FUNCTIONS	=	$(FOLDER)/push_swap.c $(FOLDER)/init_dst.c $(FOLDER)/ps_error.c $(FOLDER)/algo.c $(FOLDER)/quick_sort.c \
			$(ITEM_FOLDER)/swap.c $(ITEM_FOLDER)/push.c $(ITEM_FOLDER)/rotate.c $(ITEM_FOLDER)/reverse_rotate.c \
			$(LIBFT_FOLDER)/dst_operation.c $(LIBFT_FOLDER)/utils.c $(LIBFT_FOLDER)/ft_atol.c

all: $(NAME)

$(NAME):
	cc  -I$(INCLUDE) $(FUNCTIONS) -o push_swap

fsanitize:
	cc $(CFLAGS) -g -fsanitize=address -I$(INCLUDE) $(FUNCTIONS) -o push_swap


clean:
	$(RM) push_swap

fclean: clean
	$(RM) push_swap

re: clean all

.PHONY: all clean fclean re
