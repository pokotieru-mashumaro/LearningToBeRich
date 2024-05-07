#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>

struct s_config;

typedef	struct s_philo
{
	int	id;
    int	right_fork_id;
	int	left_fork_id;
    int eat_count;
	long long last_meal_time;
	struct s_config *config;
	pthread_t thead;
} t_philo;


typedef struct s_config
{
	int	number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
    int is_dead;
    long long start_ms;
    t_philo *philos;
	int *forks;
} t_config;


void ohhh_ikuzo(t_config *config);

t_config *init_config(char **av);

long long get_milliseconds();

int	ft_atoi(char *str);
int	ft_usleep(int milliseconds);

#endif