#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 2

long long n = 10000000000;
int thread_count = NUM_THREADS;

double factor = 1.0;
double sum = 0.0;
pthread_mutex_t mutex;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    long long i;
    double my_sum = 0.0;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor / (2 * i + 1);
    }
    pthread_mutex_lock(&mutex);
    sum += my_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    long thread;
    pthread_t* id_threads;

    pthread_mutex_init(&mutex, NULL);

    id_threads = (pthread_t*) malloc(thread_count * sizeof(pthread_t));
    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&id_threads[thread], NULL, Thread_sum, (void*) thread);
    }
    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(id_threads[thread], NULL);
    }
    double pi = 4.0 * sum;
    printf("\nNúmero de threads: %d\n", thread_count);
    printf("pi = %.15f\n", pi);

    pthread_mutex_destroy(&mutex);
    free(id_threads);

    return 0;
}
