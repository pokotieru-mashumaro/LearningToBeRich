#include "so_long.h"

int	ft_close(int keycode, t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	render_next_frame(void *game);

void	put_item(t_game *g, int x, int y)
{
	if (g->map->arrangement[y][x] == '0' || g->map->arrangement[y][x] == 'P' ||g->map->arrangement[y][x] == 'R')
		mlx_put_image_to_window(g->mlx, g->win, g->image.empty, x * 32, y * 32);
	if (g->map->arrangement[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->image.wall, x * 32, y * 32);
	if (g->map->arrangement[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->image.exit, x * 32, y * 32);
	if (g->map->arrangement[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->image.collect, x * 32, y * 32);
}

void put_map(t_game *g)
{
	int x;
	int y;

	y = 0;
	while (g->map->arrangement[y])
	{
		while (g->map->arrangement[y][x])
		{
			put_item(g,x, y);
			x++;
		}
		y++;
	}
}

void init_mlx(t_game *game)
{
	void	*mlx;
	void	*mlx_win;

	void *img;
	int img_size;

	img_size = 32;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game->map->width * 32, game->map->height * 32, "so_long");
	game->mlx = mlx;
	game->win = mlx_win;
	// mlx_hook(game->win, ON_DESTROY, 0, close, game);
	// mlx_key_hook(game->mlx, key_hook, game);
	// mlx_loop_hook(game->mlx, render_next_frame, (void *)game);
	printf("%p\n", img);
	mlx_loop(game->mlx);
}
