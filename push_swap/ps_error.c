#include "push_swap.h"

static int is_int(char *s)
{
    int i;
    int max;

    i = 0;
    max = ft_strlen(s);
    while (i < max)
    {
        if (s[i] < '0' || '9' < s[i])
            return 0;
        i++;
    }
    return 1;
}

int is_av_error(int ac, char *av[])
{
    int i;
    int j;
    char *stock[ac];

    i = 1;
    while (i < ac)
    {
        if (!is_int(av[i]))
            return 1;
        if (ft_atol(av[i]) < INT_MIN || INT_MAX < ft_atol(av[i]))
            return 1;
        j = 0;
        while (stock[j])
        {
            printf("---------\n");
            if (ft_strcmp(av[i], stock[j]) == 0)
                return 1;
            printf("¥¥¥¥¥¥¥¥¥¥¥¥¥\n");
            j++;
        }
        stock[i - 1] = av[i];
        i++;
    }
    return 0;
}
