#include "philo.h"

void give_me_the_fork()
{

}

void eating(t_philo *philo, int time_to_eat)
{
	ft_usleep(time_to_eat);
	philo->last_meal_time = get_milliseconds();
	philo->eat_count++;
}

void monitor(t_config *config)
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
		printf("%d %lld\n", philo->id, get_milliseconds());
		give_me_the_fork();
		eating(philo, config.time_to_eat);
		ft_usleep(config.time_to_sleep);
		break;
	}
	printf("%d %lld\n", philo->id, get_milliseconds());
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
	//以下に終了条件を満たすかを見るmonitor関数
	monitor(config);
}