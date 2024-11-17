#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int shared_variable = 0;
const int iter_num = 1000000;

size_t hard_work() {
    size_t sum = 0;
    for (size_t j = 0; j < 1000; ++j) {
        sum += j;
    }
    return sum;
}

void* increment(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
        size_t sum = hard_work();
        atomic_fetch_add(&shared_variable, sum);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
        size_t sum = hard_work();
        atomic_fetch_sub(&shared_variable, sum);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // increment(NULL);
    // decrement(NULL);

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_variable: %d\n", shared_variable);
    return 0;
}
