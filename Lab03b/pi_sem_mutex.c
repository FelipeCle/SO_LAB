#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 3

long long n = 1000000000;
int thread_count = NUM_THREADS;

double factor = 1.0;
double sum = 0.0;

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

    sum += my_sum;

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    long i;

    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, Thread_sum, (void*) i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    double pi = 4.0 * sum;
    printf("\nNúmero de threads:%d",NUM_THREADS);
    printf("\npi = %.15f\n", pi);

    return 0;
}
