#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}

// void	uppercase(unsigned int index, char *ch)
// {
// 	(void)index;
// 	*ch = ft_toupper(*ch);
// }

// int	main(void)
// {
// 	char str[] = "hello";
// 	ft_striteri(str, uppercase);
// 	printf("%s\n", str);
// }