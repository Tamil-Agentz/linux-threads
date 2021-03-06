#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *print_msg(void *s)
{
    printf("Message: %s\n", (char *)s);

    pthread_mutex_lock(&mutex);
    if(strcmp(s, "fool") == 0){
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }

    pthread_cond_wait(&cond, &mutex);

    printf("%s After wait...\n", (char *)s);
    pthread_mutex_unlock(&mutex);
}

main()
{
    int i = 0;
    pthread_t t1, t2, t3;
    pthread_attr_t attr;

    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&t1, 0, print_msg, "hello");
    pthread_create(&t2, 0, print_msg, "world");
    pthread_create(&t3, 0, print_msg, "fool");

    for(;;);
}
