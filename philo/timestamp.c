#include "philo.h"

long long get_milliseconds() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

// int main() {
//     long long ms = get_milliseconds();
//     printf("Current time: %lld milliseconds\n", ms);
//     return 0;
// }