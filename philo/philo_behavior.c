#include "philo.h"

void eating(t_philo *philo)
{
	t_config *config;

	config = philo->config;
	pthread_mutex_lock(&config->forks[philo->left_fork_id]);
	ft_printff(philo, "has taken a fork");		
	pthread_mutex_lock(&config->forks[philo->right_fork_id]);
	ft_printff(philo, "has taken a fork");
	ft_printff(philo, "is eating");
	philo->last_meal_time = get_milliseconds();
	philo->eat_count++;
	ft_usleep(config->time_to_eat);
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
			if (get_milliseconds() - philos[i].last_meal_time > config->time_to_die)
			{
				ft_printff(&philos[i], "died");
				config->is_dead = 1;
			}
			i++;
		}
		if (config->is_dead)
			break;
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

void ohhh_ikuzo(t_config *config)
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
