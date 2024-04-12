#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *ret;
    int i;

    ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    i = 0;
    while (*s1)
    {
        ret[i] = *s1;
        i++;
        s1++;
    }
    while (*s2)
    {
        ret[i] = *s2;
        i++;
        s2++;
    }
    ret[i] = '\0';
    return ret;
}

// int main()
// {
//     char *a = ft_strjoin("aiueo", "");
//     printf("%s\n", a);
//     return 0;
// }