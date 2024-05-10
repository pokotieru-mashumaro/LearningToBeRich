#include "philo.h"

void eating(t_philo *philo)
{
	t_config *config;

	config = philo->config;
	pthread_mutex_lock(&config->forks[philo->left_fork_id]);
	ft_printff(philo, "has taken a fork");		
	pthread_mutex_lock(&config->forks[philo->right_fork_id]);
	ft_printff(philo, "has taken a fork");
	pthread_mutex_lock(&config->eat_or_die);
	ft_printff(philo, "is eating");
	philo->last_meal_time = get_milliseconds();
	pthread_mutex_unlock(&config->eat_or_die);
	ft_usleep(config->time_to_eat);
	philo->eat_count++;
	pthread_mutex_unlock(&config->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&config->forks[philo->right_fork_id]);
}

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

void *philo_routine(void *p)
{
	t_philo *philo;
	t_config config;
	philo = (t_philo *)p;
	config = *philo->config;
	if (philo->id % 2 == 1)
		usleep(200);
	while (!config.is_dead)
	{
		eating(philo);
		if (config.is_dead)
			return NULL;
		ft_printff(philo, "is sleeping");
		ft_usleep(config.time_to_sleep);
		ft_printff(philo, "is thinking");
	}
	return NULL;
}

void banquet_of_philosophers(t_config *config)
{
	int i;
	t_philo *philos;

	i = 0;
	philos = config->philos;
	config->start_ms = get_milliseconds();
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philos[i].thead, NULL, philo_routine, &philos[i]) != 0)
			return;
		philos[i].last_meal_time = get_milliseconds();
		i++;
	}
	monitor(config);
	finish(config);
}


/*
Test: [1 800 200 200] | a philo should die

Test: [4 310 200 100] | a philo should die

Test: [4 200 205 200] | a philo should die

Test: [5 800 200 200 7] | no one should die, simulation should stop after 7 eats
Test: [4 410 200 200 10] | no one should die, simulation should stop after 10 eats
*/