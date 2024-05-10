#include <fcntl.h>      // O_CREAT
#include <semaphore.h>  // sem_wait
#include <stdio.h>      // printf
#include <unistd.h>     // sleep
#include <stdlib.h>  

char *create_philo_name(int num)
{
    char *ret;
    int num_digit;

    num_digit = 0;
    while (num > 0)
    {
        num = num / 10;
        num_digit++;
    }
    ret = (char *)malloc(6 + num_digit + 1);
    return "";
}

int main()
{
    // 1を指定するとバイナリセマフォになるよ
    sem_t *sem = sem_open("/unko", O_CREAT, 0600, 1);

    printf("ロック\n");
    sem_wait(sem);

    printf("30秒スリープ\n");
    sleep(30);
    
    printf("アンロック\n");
    sem_post(sem);
    
    return 0;
}