#include "philo.h"

void monitor(t_config *config)
{
	t_philo *philos;
	int i;

	philos = config->philos;
	i = 0;
	while (1)
	{
		while (i < config->number_of_philosophers && !config->is_dead)
		{
			pthread_mutex_lock(&config->eat_or_die);
			if (get_milliseconds() - philos[i].last_meal_time > config->time_to_die)
			{
				ft_printff(&philos[i], "died");
				config->is_dead = 1;
			}
			pthread_mutex_unlock(&config->eat_or_die);
			i++;
		}
		if (config->is_dead)
			break;
		if (all_eat_check(config) && config->number_of_times_each_philosopher_must_eat > 0)
		{
			config->is_dead = 1;
			break;
		}	
		i = 0;
	}
}

void finish(t_config *config)
{
	t_philo *philos;
	int i;
	
	philos = config->philos;
	i = 0;
	while (i < config->number_of_philosophers)
	{
		pthread_detach(philos[i].thead);
		i++;
	}
	i = 0;
	while (i < config->number_of_philosophers)
	{
		pthread_mutex_destroy(&config->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&config->printing);
	pthread_mutex_destroy(&config->eat_or_die);
}