#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strstr(const char *haystack, const char *needle)
{
	char *ptr_hy;
	char *ptr_nd;
	int count_nd;

	ptr_hy = (char *) haystack;
	ptr_nd = (char *) needle;
	while (ptr_nd[count_nd])
		count_nd++;
	while (*ptr_hy)
	{
		while (*ptr_hy == *ptr_nd)
		{
			ptr_nd++;
			if (*ptr_nd == '\0')
				return ptr_hy - count_nd + 1;
			ptr_hy++;
		}
		ptr_nd = (char *)needle;
		ptr_hy++;
	}
	return NULL;
}

int main(void)
{
	char test[20] = "abcdefghijk";
	char *p;
	p = ft_strstr(test,"fgh");
	printf("検索文字列が見つかった場所から表示→%s\n",p);
	return 0;
}
