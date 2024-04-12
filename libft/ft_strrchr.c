#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *point;

	point = NULL;
	while (s)
	{
		if (*s == (char) c)
		{
			point = (char *) s;
			printf("%s\n", point);
		}
		if (!*s)
			break;
		s++;
	}
	return point;
}

// int main(void)
// {

// 	char test[20] = "abfcdefghijk";
// 	char *p;

// 	p = ft_strrchr(test,'f');

// 	printf("検索文字が見つかった場所から表示→%s\n",p);
// 	return 0;
// }
