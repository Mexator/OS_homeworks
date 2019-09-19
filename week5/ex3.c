#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int produced = 0;
int max = 50;
int producer_sleeps = 0;
int consumer_sleeps = 1;
void produce(int *buffer)
{
    while (1)
    {
        if (!producer_sleeps)
        {
            buffer[produced] = 1;
            produced++;
            printf("Produced, %d in buffer\n", produced);
        }
        else
            printf("Producer sleeps!\n");
        producer_sleeps = max < produced;
        consumer_sleeps = produced <= 0;
        sleep(1);
    }
}
void consume(int *buffer)
{
    while (1)
    {
        if (!consumer_sleeps)
        {
            produced--;
            buffer[produced] = 0;
            printf("Consumed,%d in buffer\n", produced);
        }
        else
            printf("Consumer waits!\n");

        producer_sleeps = max < produced;
        consumer_sleeps = produced <= 0;
        sleep(2);
    }
}
int main()
{
    int *buffer = malloc(max);
    pthread_t producer, consumer;
    printf("starting threads\n");
    pthread_create(&producer, NULL, produce, buffer);
    pthread_create(&consumer, NULL, consume, buffer);
    pthread_join(producer, NULL);
}