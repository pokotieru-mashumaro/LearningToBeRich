#include "philo.h"

static void eating(t_philo *philo)
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
	philo->eat_count++;
	pthread_mutex_unlock(&config->eat_or_die);
	ft_usleep(config->time_to_eat);
	pthread_mutex_unlock(&config->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&config->forks[philo->right_fork_id]);
}

static void sleeping(t_philo *philo)
{
	ft_printff(philo, "is sleeping");
	ft_usleep(philo->config->time_to_sleep);
}

static void thinking(t_philo *philo)
{
	ft_printff(philo, "is thinking");
}

static void *philo_routine(void *p)
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
		sleep(philo);
		thinking(philo);
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