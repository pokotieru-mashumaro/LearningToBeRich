#include "libft.h"

char *ft_strndup(const char *s1, size_t n)
{
	int i;
	int len;
	char *ans;

	if (n == 0)
		return NULL;
	i = 0;
	while (s1[i])
	{
		if (i < n)
			ans[i] = s1[i];
		i++;
	}
	return ans;
}

int main()
{
	char *str = ft_strndup("fuck!!", 6);
	printf("%s", str);
}
