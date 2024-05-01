#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_space
{
	int		x;
	int		y;
    char	object;
}	t_space;

typedef struct s_map
{
	int width;
    int height;
    char **arrangement;
    t_space *wall;
    t_space *collectibles;
    t_space *enemy;
    t_space *exit;
}	t_map;

typedef struct s_collectibles {
	int	total;
	int	got;
}	t_collectibles;

typedef struct s_player {
	int	x;
	int	y;
	int step_count;
    t_collectibles collect;
}	t_player;

typedef struct s_game {
	char *file_name;
    t_map *map;
    t_player player;
}	t_game;

void init_game(t_game *game);

#endif