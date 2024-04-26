#include "so_long.h"

/*
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position
*/

/*
"bonus"
• Make the player lose when they touch an enemy patrol.
• Add some sprite animation.
• Display the movement count directly on screen instead of writing it in the shell.
*/

void count_w_h(t_map *map)
{

}

t_map *init_map()
{
    t_map *map;

    return map;
}

int game_error(t_game *game)
{
    return 0;
}

void init_game(t_game *game)
{
    int fd;

    fd = open(game->file_name, O_RDONLY);
    game->map = init_map();
    return ;
}

static int check_ber(char *s1, char *s2)
{
    int count;
    int i;
    int j;

    count = 0;
    while (s1[count])
        count++;
    if (count <= 4)
        return 0;
    i = count - 4;
    j = 0;
    while (j < 4)
    {
        if (s1[i] != s2[j])
            return 0;
        i++;
        j++;
    }
    return 1;
}

int check_input(int ac, char **av)
{
    if (ac != 2)
        return 0;
    if (!check_ber(av[1], ".ber"))
        return 0;
    return 1;
}

int main(int ac, char **av)
{
    t_game game;

    if (!check_input(ac, av))
        return 0;
    init_game(&game);
    printf("-------\n");
    return 0;
}