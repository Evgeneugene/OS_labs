#include <stdio.h>
#include <time.h>
#include <pthread.h>
const int N = 100;
char buffer[N];
int count = 0;
int c = 0;
time_t start;
pthread_mutex_t mutex;
pthread_cond_t cond_consumer, cond_producer;

void *Producer(void *pthread) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == N) {
            pthread_cond_wait(&cond_producer, &mutex);
        }
        buffer[count] = 'P';
        count++;
        time_t end = time(NULL);
        double time_spent = (double)(end - start);
        if (time_spent > c*60) {
            printf("Time of execution:%f\n", time_spent);
            c++;
        }
        if (count == 1) {
            pthread_cond_signal(&cond_consumer);
            pthread_mutex_unlock(&mutex);
        }
    }
}

void *Consumer(void *pthread) {
    while (1) { /* repeat forever */
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }
        buffer[count] = 'C';
        count--;
        if (count == N - 1) {
            pthread_cond_signal(&cond_producer);
            pthread_mutex_unlock(&mutex);
        }
    }
}


int main(int argc, char const *argv[]) {
    start = time(NULL);
    pthread_t producer, consumer;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_consumer, NULL);
    pthread_cond_init(&cond_producer, NULL);
    pthread_create(&consumer, NULL, Consumer, NULL);
    pthread_create(&producer, NULL, Producer, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    pthread_cond_destroy(&cond_consumer);
    pthread_cond_destroy(&cond_producer);
    pthread_mutex_destroy(&mutex);
    return 0;
}
