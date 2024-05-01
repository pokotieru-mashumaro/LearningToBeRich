#include "so_long.h"

/*
初期化：

*/

void count_w_h(char *file_name, t_map *map)
{
    int fd;
    char *line;
    int width;
    int height;

    fd = open(file_name, O_RDONLY);
    width = 0;
    height = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        width = ft_strlen(line);
        height++;
    }
    close(fd);
    map->width = width;
    map->height = height;
}

int ft_strlen(char *s)
{
    int i;

    while (s[i])
        i++;
    return i;
}

t_map *init_map(t_game *game, int fd)
{
    t_map *map;
    char *line;
    char **arrangement;
    int i;

    i = 0;
    count_w_h(game->file_name, map);
    arrangement = (char **)malloc(map->height * sizeof(char *));
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        arrangement[i] = line;
        i++;
    }
    map->arrangement = arrangement;
    return map;
}

void init_game(t_game *game)
{
    int fd;
    int x;
    int y;

    fd = open(game->file_name, O_RDONLY);
    game->map = init_map(game, fd);
    close(fd);
    return ;
}