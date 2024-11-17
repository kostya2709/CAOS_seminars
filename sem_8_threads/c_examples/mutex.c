#include <stdio.h>
#include <pthread.h>

int shared_variable = 0;
pthread_mutex_t mutex;
const int iter_num = 10000000;

void* increment(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
        pthread_mutex_lock(&mutex);
		++shared_variable;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < iter_num; ++i) {
		pthread_mutex_lock(&mutex);
        --shared_variable;
		pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {

	pthread_mutex_init(&mutex, NULL);
	pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex);

    printf("Final value of shared_variable: %d\n", shared_variable);
    return 0;
}
