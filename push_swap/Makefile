NAME = push_swap
INCLUDE = includes/push_swap.h
CFLAGS	=	-Wall -Wextra -Werror
RM			=	rm -f

FOLDER = src
ITEM_FOLDER = src/items
LIBFT_FOLDER = src/libft

FUNCTIONS	=	$(FOLDER)/push_swap.c $(FOLDER)/init_dst.c $(FOLDER)/ps_error.c $(FOLDER)/dame.c $(FOLDER)/radix_sort.c $(FOLDER)/separated_by_pivot.c $(FOLDER)/coordinate_press.c\
			$(ITEM_FOLDER)/swap.c $(ITEM_FOLDER)/push.c $(ITEM_FOLDER)/rotate.c $(ITEM_FOLDER)/reverse_rotate.c \
			$(LIBFT_FOLDER)/dst_operation.c $(LIBFT_FOLDER)/utils.c $(LIBFT_FOLDER)/ft_atol.c $(LIBFT_FOLDER)/ft_split.c

OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -I$(INCLUDE) $(OBJ) -o push_swap

.c.o:
	cc $(CFLAGS) -I $(INCLUDE) -c $< -o $@

fsanitize:
	cc $(CFLAGS) -g -fsanitize=address -I$(INCLUDE) $(FUNCTIONS) -o push_swap

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
