#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	size_t i;
	unsigned char *point;

	i = 0;
	point = (unsigned char *) b;
	while (i < len)
	{
		point[i] = (unsigned char) c;
		i++;
	}
	return b;
}

// int main() {
// 	int array[5];
// 	ft_memset(array, 0, sizeof(array));
	
// 	for(int i = 0; i < 5; i++) {
// 		printf("%d ", array[i]);
// 	}
// 	return 0;
// }

