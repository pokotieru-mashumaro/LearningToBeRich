#include "philo.h"

void eating(t_philo *philo)
{
	t_config *config;

	config = philo->config;
	pthread_mutex_lock(&config->forks[philo->left_fork_id]);
	ft_printff(philo, "left fork");
	pthread_mutex_lock(&config->forks[philo->right_fork_id]);
	ft_printff(philo, "right fork");
	ft_printff(philo, "eating");
	ft_usleep(config->time_to_eat);
	philo->eat_count++;
	philo->last_meal_time = get_milliseconds();
	pthread_mutex_unlock(&config->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&config->forks[philo->right_fork_id]);
}

void monitor(t_config *config)
{
	t_philo *philos;
	int i;

	philos = config->philos;
	i = 0;
	while (i < config->number_of_philosophers && !config->is_dead)
	{
		if (philos[i].last_meal_time -get_milliseconds() > config->time_to_die)
		{
			ft_printff(&philos[i], "die");
			config->is_dead = 1;
		}
		if (config->is_dead)
			break;
		i++;
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
		pthread_join(philos[i].thead, NULL);
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
	while (1)
	{
		eating(philo);
		ft_printff(philo, "sleeping");
		ft_usleep(config.time_to_sleep);
		ft_printff(philo, "thinking");
		break;
	}
	printf("%d %lld\n", philo->id, get_milliseconds());
	return NULL;
}

void ohhh_ikuzo(t_config *config)
{
	int i;
	t_philo *philos;


	i = 0;
	philos = config->philos;
	while (i < config->number_of_philosophers)
	{
		if (pthread_create(&philos[i].thead, NULL, philo_routine, &philos[i]) != 0)
			return;
		philos[i].last_meal_time = get_milliseconds();
		i++;
	}
	finish(config);
}
