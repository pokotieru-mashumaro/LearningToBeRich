#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

enum direction
{
    RIGHT,
    LEFT
};

typedef struct s_map
{
	int width;
    int height;
    char **arrangement;
    int n_collectibles;
    int n_player;
    int n_enemy;
    int n_exit;
}	t_map;

typedef struct s_image {
	void *player;
    void *enemy;
    void *empty;
    void *wall;
    void *collect;
    void *exit;
}	t_image;

typedef struct s_player {
	int	x;
	int	y;
	int step_count;
}	t_player;

typedef struct s_game {
	char *file_name;
    void *mlx;
    void *win;
    t_map *map;
    t_player player;
    t_player *enemies;
    t_image *image;
    int get_collect;
}	t_game;

void init_game(t_game *game, char **av);
t_map *init_map(t_game *game, int fd);
t_player init_player(t_map *m);
t_player *init_enemies(t_map *m);

void init_mlx(t_game *game);

int ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *s1);
char	**ft_split(const char *s, char c);
#endif
