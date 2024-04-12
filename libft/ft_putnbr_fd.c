#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	arr[10];
	int		i;

	nb = n;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (nb > 0)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(fd, &arr[i], 1);
	}
}
