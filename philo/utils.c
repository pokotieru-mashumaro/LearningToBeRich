#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	int			ans;

	i = 0;
	ans = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return (ans);
}

int	ft_usleep(int milliseconds)
{
	int	start;

	start = get_milliseconds();
	while ((get_milliseconds() - start) < milliseconds)
		usleep(500);
	return (0);
}
