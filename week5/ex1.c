#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void thread_func(int number)
{
    printf("Hi from thread #%d\n", number);
}
int main()
{
    pthread_t thread;
    int i = 0;
    for (i; i < N; i++)
    {
        printf("Creating thread #%d\n", i);
        pthread_create(&thread, NULL, thread_func, i);
        pthread_join(thread, NULL);
    }
}