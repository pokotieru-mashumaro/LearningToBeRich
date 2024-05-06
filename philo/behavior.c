#include "philo.h"

int	ft_usleep(int milliseconds)
{
	int	start;

	start = get_milliseconds();
	while ((get_milliseconds() - start) < milliseconds)
		usleep(500);
	return (0);
}
