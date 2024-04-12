#include "libft.h"

int ft_atoi(const char *str)
{
	int i;
	int minus;
	int ans;

	i = 0;
	minus = 1;
	ans = 0;
	while (str[i] == '\t' || str[i] == '\n' ||str[i] == '\v' ||str[i] == '\f' ||str[i] == '\r' ||str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return minus * ans;
}

// int main()
// {
// 	printf("%d\n", ft_atoi("1234"));
// 	printf("%d\n", ft_atoi("0"));
// 	printf("%d\n", ft_atoi("1234"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// }

