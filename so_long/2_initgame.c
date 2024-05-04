#include "so_long.h"

/*
初期化：

*/

void init_image_path(t_game *game)
{
    t_image *image;
    int size;

    size = 32;
    image = (t_image *)malloc(sizeof(t_image));
    image->player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &size, &size);
    image->enemy = mlx_xpm_file_to_image(game->mlx, "xpm/enemy.xpm", &size, &size);
    image->empty = mlx_xpm_file_to_image(game->mlx, "xpm/empty.xpm", &size, &size);
    image->wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &size, &size);
    image->collect = mlx_xpm_file_to_image(game->mlx, "xpm/collect.xpm", &size, &size);
    image->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &size, &size);
    game->image = image;
    free(image);
}

void init_game(t_game *game, char **av)
{
    int fd;
    int x;
    int y;

    fd = open(av[1], O_RDONLY);
    game->map = init_map(game, fd);
    game->player = init_player(game->map);
    game->enemies = init_enemies(game->map);
    init_mlx(game);
    init_image_path(game);
    game->get_collect = 0;
    close(fd);
    printf("init完了\n");
    return ;
}
