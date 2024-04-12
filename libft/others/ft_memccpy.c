#include "libft.h"

void *ft_memccpy(void *restrict dst, const void *restrict src, int c,size_t n)
{
	size_t i;
	unsigned char *d_ptr;
	unsigned char *s_ptr;

	i = 0;
	d_ptr = (unsigned char *)dst;
	s_ptr = (unsigned char *)src;
	while (i < n)
	{
		*d_ptr = s_ptr[i];
		d_ptr++;
		if (s_ptr[i] == (unsigned char) c)
			return (d_ptr);
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
  char dest[64];
  char *src;
  char *p;
  int c;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s [string] [stopping character]\n", argv[0]);
    exit(1);
  }

  src = argv[1];
  c = argv[2][0];

  p = memccpy(dest, src, c, strlen(src) + 1);
  if (p != NULL) {
    *p = '\0';
  }

  printf("src  = %s\n", src);
  printf("dest = %s\n", dest);

  return 0;
}
