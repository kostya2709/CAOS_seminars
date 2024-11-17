#include <stdio.h>
#include <pthread.h>

int shared_variable = 0;
const int iter_num = 10000000;

void* increment(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
        ++shared_variable;
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
        --shared_variable;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_variable: %d\n", shared_variable);
    return 0;
}
