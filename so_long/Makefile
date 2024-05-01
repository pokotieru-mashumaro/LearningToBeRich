NAME = so_long
SRCS = 1_so_long.c 2_initgame.c 2_initmap.c 2_initplayer.c 3_mlx1.c ft_split.c ft_strjoin.c
OBJ = $(SRCS:.c=.o)
INCLUDE = so_long.h

CFLAG = -Wall -Wextra -Werror
GNLDIR = get_next_line
GNL = $(GNLDIR)/get_next_line.a
MLXDIR = mlx
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
# @$(MAKE) -C $(MLXDIR)
# $(MAKE) -C $(GNLDIR)
	cc $(CFLAG) $(OBJ) $(MLX) $(GNL) -o $(NAME)

.c.o:
	@cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJ)
# @$(MAKE) -C $(MLXDIR) clean
# @$(MAKE) -C $(GNLDIR) clean

fclean: clean
	rm -f $(NAME)
# @$(MAKE) -C $(MLXDIR) clean
# @$(MAKE) -C $(GNLDIR) fclean


re : fclean all

.PHONY: all clean fclean re
