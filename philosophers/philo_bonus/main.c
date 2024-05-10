#include "philo_bonus.h"

int free_config(t_config *config)
{
    if (config->philos != NULL)
	    free(config->philos);
    if (config->forks != NULL)
	    free(config->forks);
    if (config != NULL)
	    free(config);
    return 0;
}

int main(int ac, char **av)
{
    t_config *config;

    if (ac != 5 && ac != 6)
        return (0);
    config = init_config(av);
	if (!config)
    {
        printf("init error\n");
		return 0;
    }
	banquet_of_philosophers(config);
    return free_config(config);
}
