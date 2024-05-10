#include "philo.h"

t_config *init_config(char **av)
{
    t_config *config;

    config = (t_config *)malloc(sizeof(t_config));
    config->number_of_philosophers = ft_atoi(av[1]);
    config->time_to_die = ft_atoi(av[2]);
    config->time_to_eat = ft_atoi(av[3]);
    config->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        config->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        config->number_of_times_each_philosopher_must_eat = -1;
    if (config->number_of_philosophers < 1 || config->number_of_philosophers > 200 || config->time_to_die < 0 || config->time_to_eat < 0 || config->time_to_sleep < 0 || (config->number_of_times_each_philosopher_must_eat != -1 && config->number_of_times_each_philosopher_must_eat <= 0))
        return NULL;
    if (pthread_mutex_init(&(config->printing), NULL))
        return NULL;
    if (pthread_mutex_init(&(config->eat_or_die), NULL))
        return NULL;
    if (init_philos_forks(config))
        return NULL;
    return config;
}
