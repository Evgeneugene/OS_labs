#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *ThreadCreation(void *arg)
{
    int *id = (int*)arg;
    static int s = 0;
    ++s;
    printf("Created thread ID: %d, Static: %d\n", *id, s);
}

int main()
{
    int i;
    pthread_t id;
    for (i = 0; i < 3; i++) {
        pthread_create(&id, NULL, ThreadCreation, (void *) &id);
        pthread_join(id, NULL);
    }
    pthread_exit(NULL);
    return 0;
}