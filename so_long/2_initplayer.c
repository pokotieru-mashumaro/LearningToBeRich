#include "so_long.h"

t_player init_player(t_map *m)
{
    char **map;
    t_player player;
    int x;
    int y;

    map = m->arrangement;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                player.x = x;
                player.y = y;
                player.step_count = 0;
                return player;
            }
            x++;
        }
        y++;
    }
    return player;
}

static t_player new_enemy(int x, int y)
{
    t_player enemy;

    enemy.x = x;
    enemy.y = y;
    enemy.step_count = 0;
    return enemy;
}

t_player *init_enemies(t_map *m)
{
    char **map;
    t_player *enemies;
    int x;
    int y;
    int i;

    map = m->arrangement;
    enemies = (t_player *)malloc(m->n_enemy * sizeof(t_player));
    y = 0;
    i = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'R')
            {
                enemies[i] = new_enemy(x, y);
                i++;
            }
            x++;
        }
        y++;
    }
    return enemies;
}
