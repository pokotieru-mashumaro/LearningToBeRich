#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;
	char *ptr_dst;
	char *ptr_src;

	if (!dst && !src)
		return NULL;
	i = 0;
	ptr_dst = (char *) dst;
	ptr_src = (char *) src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return dst;
}

// int main(void)
// {
// 	char buf[] = "ABCDDEFG";
// 	char buf2[] = "123456789";
// 	//3バイトだけコピー
// 	memcpy(buf,buf2,3);
// 	//表示
// 	printf("コピー後のbuf文字列→%s\n",buf);
// 	return 0;
// }
