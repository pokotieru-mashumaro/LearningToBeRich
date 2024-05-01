#include "so_long.h"

/*
初期化：

*/

void init_image_path(t_game *game)
{
    t_image image;
    int size;

    size = 32;

    image = game->image;
    image.player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &size, &size);
    image.enemy = mlx_xpm_file_to_image(game->mlx, "xpm/enemy.xpm", &size, &size);
    image.empty = mlx_xpm_file_to_image(game->mlx, "xpm/empty.xpm", &size, &size);
    image.wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &size, &size);
    image.collect = mlx_xpm_file_to_image(game->mlx, "xpm/collect.xpm", &size, &size);
    image.exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &size, &size);
}

void init_game(t_game *game, char **av)
{
    int fd;
    int x;
    int y;

    game->file_name = av[1];
    fd = open(game->file_name, O_RDONLY);
    game->map = init_map(game, fd);
    game->player = init_player(game->map);
    game->enemies = init_enemies(game->map);
    init_image_path(game);
    game->get_collect = 0;
    close(fd);
    return ;
}
