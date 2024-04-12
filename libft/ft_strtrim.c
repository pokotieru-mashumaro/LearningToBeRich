#include "libft.h"

int	find_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s1[start] && find_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (find_set(s1[end - 1], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	ret = (char *)malloc(end - start + 1);
	i = 0;
	while (start < end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	return (ret);
}

// int	main(void)
// {
// 	char *a = ft_strtrim("   xxx   xxx", " x");
// 	printf("%s", a);
// 	return (0);
// }