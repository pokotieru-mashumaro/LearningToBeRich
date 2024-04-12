#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(little))
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len))
	{
		j = 0;
		while ((i + j < len) && (big[i + j] == little[j]))
		{
			if (!little[j + 1])
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	char	*ptr_big;
// 	char	*ptr_little;
// 	int		count_little;

// 	count_little = ft_strlen(little);
// 	if (!count_little)
// 		return (ptr_big);
// 	if (len == 0)
// 		return (NULL);
// 	while (*ptr_big && len > 0)
// 	{
// 		while ((*ptr_big == *ptr_little) && len > 0)
// 		{
// 			ptr_little++;
// 			if (!*ptr_little)
// 				return (ptr_big - count_little + 1);
// 			ptr_big++;
// 			len--;
// 		}
// 		ptr_little = (char *)little;
// 		ptr_big++;
// 		len--;
// 	}
// 	printf("aaa\n");
// 	return (NULL);
// }

// int	main(void)
// {
// 	const char *largestring = "aaabcabcd";
// 	const char *smallstring = "aabc";
// 	char *ptr;

// 	ptr = strnstr(largestring, smallstring, 9);
// 	printf("%s\n", ptr);
// 	ptr = ft_strnstr(largestring, smallstring, 9);
// 	printf("%s\n", ptr);
// 	return (0);
// }