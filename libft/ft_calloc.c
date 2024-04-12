#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

// int main(void)
// {
//     int* values = ft_calloc(10, sizeof(int));
//     if (values == NULL) {
//         exit(EXIT_FAILURE);
//     }

//     for (int i = 0; i < 10; ++i) {
//         printf("%d ", values[i]);
//     }
//     printf("\n");

//     for (int i = 0; i < 10; ++i) {
//         values[i] = i;
//     }

//     for (int i = 0; i < 10; ++i) {
//         printf("%d ", values[i]);
//     }
//     printf("\n");

//     free(values);
// }
