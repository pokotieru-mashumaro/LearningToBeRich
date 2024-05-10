#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	int			ans;

	i = 0;
	ans = 0;
	if (str[i] == '-')
		return -42;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return (ans);
}

long long get_milliseconds() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int	ft_usleep(long long time)
{
	long long	start;

	start = get_milliseconds();
	while ((get_milliseconds() - start) < time)
		usleep(50);
	return (0);
}

void ft_printff(t_philo *philo, char *s)
{
	t_config *config;
	long long	time;

	config = philo->config;
	if (config->start_ms > 0)
	{
		time = get_milliseconds() - config->start_ms;
		pthread_mutex_lock(&(config->printing));
		printf("%lld %d %s\n", time, philo->id + 1, s);
		pthread_mutex_unlock(&(config->printing));
	}
}

//0: 
//1: all eat
int all_eat_check(t_config *config)
{
	t_philo *philos;
	int i;

	philos = config->philos;
	i = 0;
	while (i < config->number_of_philosophers)
	{
		if (philos[i].eat_count < config->number_of_times_each_philosopher_must_eat)
			return 0;
		i++;
	}
	return 1;
}