#include "philo.h"


static void init_philos(t_rules *rules)
{
    int i;
    t_philo *philos;

    i = 0;
    philos = (t_philo *)malloc(rules->number_of_philosophers * sizeof(t_rules));
    while (i < rules->number_of_philosophers)
    {
        philos[i].id = i;
        philos[i].right_fork_id = i;
        philos[i].left_fork_id = (i + 1) % rules->number_of_philosophers;
        philos[i].eat_count = 0;
        i++;
    }    
    rules->philos = philos;
}

int init_rules(t_rules *rules, char **av)
{
    rules->number_of_philosophers = ft_atoi(av[1]);
    rules->time_to_die = ft_atoi(av[2]);
    rules->time_to_eat = ft_atoi(av[3]);
    rules->time_to_sleep = ft_atoi(av[4]);
    rules->start_ms = get_milliseconds();
    if (av[5])
        rules->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        rules->number_of_times_each_philosopher_must_eat = -1;
    if (rules->number_of_philosophers < 2 || rules->number_of_philosophers >= 200  || rules->time_to_die < 0 || rules->time_to_eat < 0 || rules->time_to_sleep < 0 || (rules->number_of_times_each_philosopher_must_eat != -1 && rules->number_of_times_each_philosopher_must_eat <= 0))
        return 1;
    init_philos(rules);
    return 0;
}