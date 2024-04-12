#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s)
			return NULL;
		s++;
	}
	return (char *)s;
}

// int main(void)
// {

// 	char test[20] = "abcdefghijk";
// 	char *p;

// 	p = ft_strchr(test,'f');

// 	printf("検索文字が見つかった場所から表示→%s\n",p);
// 	return 0;
// }
