#include "philo.h"

static int init_philos_forks(t_config *config)
{
    int i;
    t_philo *philos;
    int *forks;

    i = 0;
    philos = (t_philo *)malloc(config->number_of_philosophers * sizeof(t_config));
    forks = (pthread_mutex_t *)malloc(config->number_of_philosophers * sizeof(pthread_mutex_t));
    while (i < config->number_of_philosophers)
    {
        philos[i].id = i;
        philos[i].right_fork_id = i;
        philos[i].left_fork_id = (i + 1) % config->number_of_philosophers;
        philos[i].eat_count = 0;
        philos[i].last_meal_time = 0;
        philos[i].config = config;
        philos[i].thead = NULL;
        forks[i] = NULL;
        if (pthread_mutex_init(&(config->forks[i]), NULL))
			return 1;
        i++;
    }
    config->philos = philos;
    config->forks = forks;
    return 0;
}

t_config *init_config(char **av)
{
    t_config *config;

    config = (t_config *)malloc(sizeof(t_config));
    config->number_of_philosophers = ft_atoi(av[1]);
    config->time_to_die = ft_atoi(av[2]);
    config->time_to_eat = ft_atoi(av[3]);
    config->time_to_sleep = ft_atoi(av[4]);
    config->start_ms = get_milliseconds();
    if (pthread_mutex_init(&(config->i_would_like_to_have_a_fork), NULL))
		return NULL;
    if (pthread_mutex_init(&(config->printing), NULL))
		return NULL;
    if (av[5])
        config->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        config->number_of_times_each_philosopher_must_eat = -1;
    if (config->number_of_philosophers < 2 || config->number_of_philosophers >= 200  || config->time_to_die < 0 || config->time_to_eat < 0 || config->time_to_sleep < 0 || (config->number_of_times_each_philosopher_must_eat != -1 && config->number_of_times_each_philosopher_must_eat <= 0))
        return NULL;
    if (init_philos_forks(config))
        return NULL;
    return config;
}
