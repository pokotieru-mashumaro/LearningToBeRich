#include "libft.h"

char *ft_strdup(const char *s1)
{
	int i;
	char *ans;

	i = 0;
	ans = (char *)malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	return ans;
}

// int main()
// {
// 	char *str = ft_strdup("fuck!!");
// 	printf("%s", str);
// }
