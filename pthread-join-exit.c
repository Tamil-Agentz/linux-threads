#include<stdio.h>
#include<pthread.h>

void *print_msg(void *s)
{
    int i = 0;

    while(i < 100000){
        printf("%s: %d\n", (char *)s, i);
        i++;
    }
}

main()
{
    pthread_t t1, t2;

    pthread_create(&t1, 0, print_msg, "thread 1");
    pthread_join(t1, 0);

    pthread_create(&t2, 0, print_msg, "thread 2");

    while(1);
}
