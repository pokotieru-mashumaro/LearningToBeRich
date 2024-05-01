#include "so_long.h"

static int count_width(char **arrangement)
{
    int i;
    int width;
    int stock;

    i = 0;
    width = 0;
    stock = 0;
    while (arrangement[i])
    {
        stock = ft_strlen(arrangement[i]);
        if (width < stock)
            width = stock;
        i++;
    }
    return stock;
}

static void set_n(t_map *m)
{
	char **map;
	int x;
	int y;

	map = m->arrangement;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				m->n_collectibles++;
			else if (map[y][x] == 'E')
				m->n_exit++;
			else if (map[y][x] == 'P')
				m->n_player++;
			else if (map[y][x] == 'R')
				m->n_enemy++;
			x++;
		}
		y++;
	}
	return;
}

static void read_arrangement(int fd, t_map *map)
{
    char *line;
    char *all;

    line = NULL;
    all = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            if (!map->height)
                printf("error\n");
            break;
        }
        all = ft_strjoin(all, line);
        map->height++;
    }
    map->arrangement = ft_split(all, '\n');
    map->width = count_width(map->arrangement);
    free(line);
    free(all);
    return;
}

//error handring
/*
- 1 player only
*/
t_map *init_map(t_game *game, int fd)
{
    t_map *map;

    read_arrangement(fd, map);
	set_n(map);
    return map;
}
