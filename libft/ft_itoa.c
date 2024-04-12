#include "libft.h"

int count_digit(long n)
{
    int count;

    count = 1;
    while (n /= 10)
        count++;
    return count;
}

char *ft_itoa(int n)
{
    long tmp;
    int digit;
    char *ans;

    tmp = n;
    digit = count_digit(tmp);
    if (n < 0)
    {
        tmp *= -1;
        digit++;
    }
    ans = (char *)malloc(digit + 1);
    if (!ans)
        return NULL;
    while (digit--)
    {
        ans[digit] = (tmp % 10) + '0';
        tmp /= 10; 
    }
    if (n < 0)
        ans[0] = '-';
    return ans;
}

// int main()
// {
//     printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(42));
//     printf("%s\n", ft_itoa(2147483647));
//     printf("%s\n", ft_itoa(-2147483648));
//     return 0;
// }    
