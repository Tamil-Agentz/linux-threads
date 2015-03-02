#include<stdio.h>
#include<pthread.h>

void *fun(void *arg)
{
    int i;

    while(1){
        for(i = 0; i < 5; i++){
            printf("%s: %d\n", (char *)arg, i);
            sleep(1);
        }
    }
}

main()
{
    pthread_t t1, t2;

    pthread_create(&t1, 0, fun, "thread 1");
    pthread_create(&t2, 0, fun, "thread 2");

    while(1);
}
