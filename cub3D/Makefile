NAME		=	cub3D
SRCS		=	main.c window.c hooks.c image.c color.c
LIBFT = libft/libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -f
OBJS		=	$(SRCS:.c=.o)
MLX         =   mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C libft
	@$(CC) $(MLX) $(LIBFT) $(CFLAGS) $^ -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

fclean: clean
	$(MAKE) fclean -C libft
	@$(RM) $(NAME)

clean:
	$(MAKE) clean -C libft
	@$(RM) $(OBJS)

re:	fclean all

.PHONY:	all clean fclean re