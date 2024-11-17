#include <pthread.h>
#include <stdio.h>

size_t get_rsp() {
    size_t x = 0;
    return (size_t)(&x + 4);
}

size_t get_rip() {
    size_t x = 0;
    return *(&x + 3);
}

struct SomeData {
	int data;
};

void* some_work(void* arg) {
	printf("work thread id: 0x%lx, rsp = 0x%lx, rip = 0x%lx, data = %s\n",
			pthread_self(), get_rsp(), get_rip(), (char*)arg);
    
	for (int i = 0; i < 5; ++i) {
        puts(arg);
		sched_yield();
	}
    
	return NULL;
}

void* some_work_data(void* arg) {
	struct SomeData this_thread_data = *(struct SomeData*)arg;
	printf("work thread id: 0x%lx, rsp = 0x%lx, rip = 0x%lx, data = %d\n",
			pthread_self(), get_rsp(), get_rip(), this_thread_data.data);
    
	for (int i = 0; i < 5; ++i) {
        printf("%d\n", this_thread_data.data);
    }
    
	return "Work done";
}
int main(void) 
{ 
    pthread_t thread1, thread2, thread3;

	printf("main thread id: 0x%lx\n", pthread_self());

	pthread_create(&thread1, NULL, some_work, "Thread1 works..." );
    pthread_create(&thread2, NULL, some_work, "Thread2 works..." );
    
	struct SomeData data = {.data = 27};
	pthread_create(&thread3, NULL, some_work_data, &data);
 
    printf("End...\n");
	printf("main thread id: %lx, rsp = 0x%lx, rip = 0x%lx\n", pthread_self(), get_rsp(), get_rip());
	printf("main thread: thread1 = %lx, thread2 = %lx\n", thread1, thread2);

	void* thread3_res_ptr = NULL;
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, &thread3_res_ptr);

	printf("thread3 result = %s\n", (char*)thread3_res_ptr);

	return 0;
}
